/*
 * Arena 360 - bootstrap técnico
 * Base inicial de vídeo/entrada para Xbox 360 RGH/JTAG com XSDK.
 * Ainda não contém combate, personagens ou arenas jogáveis.
 */
#include <stdint.h>

#include "xsdk/gpu.h"
#include "xsdk/kernel.h"
#include "xsdk/log.h"
#include "xsdk/present.h"
#include "xsdk/splash.h"

enum {
    DISPLAY_BUFFERS = 2,
    SWAP_INTERVAL = 1,
    BEGIN_TIMEOUT_MS = 5000,
    CLEAR_ARGB = 0xFF101522
};

static int run_title(uint32_t width, uint32_t height)
{
    for (;;) {
        INPUT_STATE input = {0};

        if (XamInputGetState(0, 0, &input) == ERROR_SUCCESS &&
            (input.gamepad.buttons & INPUT_GAMEPAD_BACK) != 0) {
            break;
        }

        uint32_t back_buffer = 0;
        NTSTATUS status = xsdk_present_begin(&back_buffer, BEGIN_TIMEOUT_MS);
        if (!NT_SUCCESS(status)) {
            xsdk_log_write("Arena360: present_begin falhou: 0x%08X",
                           (unsigned)status);
            return 1;
        }

        /* Fase inicial: limpar o ecrã. A renderização do jogo entra aqui. */
        xsdk_gpu_resolve(back_buffer, width, height, CLEAR_ARGB);
        xsdk_present_end();
    }

    return 0;
}

int main(void)
{
    xsdk_log_write("Arena360: inicializando");

    NTSTATUS status = xsdk_splash_show(1500);
    if (!NT_SUCCESS(status)) {
        xsdk_log_write("Arena360: splash indisponivel: 0x%08X",
                       (unsigned)status);
    }

    status = xsdk_gpu_open();
    if (!NT_SUCCESS(status)) {
        xsdk_log_write("Arena360: gpu_open falhou: 0x%08X",
                       (unsigned)status);
        return 1;
    }

    uint32_t width = 0;
    uint32_t height = 0;
    status = xsdk_present_open(XSDK_DISPLAY_720P, DISPLAY_BUFFERS,
                               SWAP_INTERVAL, &width, &height);
    if (!NT_SUCCESS(status)) {
        xsdk_log_write("Arena360: present_open falhou: 0x%08X",
                       (unsigned)status);
        (void)xsdk_gpu_close();
        return 1;
    }

    xsdk_log_write("Arena360: video inicializado em %ux%u",
                   (unsigned)width, (unsigned)height);

    const int result = run_title(width, height);

    xsdk_present_close();
    status = xsdk_gpu_close();
    if (!NT_SUCCESS(status)) {
        xsdk_log_write("Arena360: gpu_close falhou: 0x%08X",
                       (unsigned)status);
    }

    xsdk_log_write("Arena360: encerrado");
    return result;
}

#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInst;
HWND h_texto, h_sim, h_nao; /// CONTROLE PARA OS BOTÕES E PARA O TEXTO

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        h_texto = GetDlgItem(hwndDlg, TEXTO);
        h_sim   = GetDlgItem(hwndDlg, BOTAO_SIM);
        h_nao   = GetDlgItem(hwndDlg, BOTAO_NAO);

        HFONT fonte_texto = CreateFont(-40, 25, true, true, true, false, false, false, false,
                                       true, true, true, true, "Consolas Bold");
                                       /// 3 true, 4 false, 4 true
        HFONT fonte_botao = CreateFont(-20, 10, true, true, true, false, false, false, false,
                                       true, true, true, true, "Consolas");
                                       /// 3 true, 4 false, 4 true

        SendMessage(h_texto, WM_SETFONT, (WPARAM)fonte_texto, true); /// Atribuindo a fonte ao texto
        SendMessage(h_sim, WM_SETFONT, (WPARAM)fonte_botao, true);
        SendMessage(h_nao, WM_SETFONT, (WPARAM)fonte_botao, true); /// Atribuindo a fonte aos botões
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            case BOTAO_NAO: /// SE O BOTÃO "NÃO" FOR CLICADO
            {
                int x = rand()%300;
                int y = rand()%125+50;

                SetWindowPos(h_nao, (HWND)0, x, y, 0, 0, SWP_NOSIZE);
                /// ATRIBUINDO NOVA POSIÇÃO AO BOTÃO "NÃO"
                break;
            }

            case BOTAO_SIM: /// SE O BOTÃO "SIM" FOR CLICADO
            {
                SetWindowText(h_texto, "Eu sempre soube.");
                /// ALTERA O TEXTO DA JANELA
                break;
            }
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}

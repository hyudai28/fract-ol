/*************************/
/*  ジュリア集合         */
/*             Windows版 */
/*************************/
#include <stdio.h>
#include <windows.h>


#define  XMAX  800                                      // ｳｨﾝﾄﾞｳ Xmax
#define  YMAX  800                                      // ｳｨﾝﾄﾞｳ Ymax

HWND    hWnd=NULL;                                      // ｳｨﾝﾄﾞｳのﾊﾝﾄﾞﾙ
MSG     msg;                                            // ｳｨﾝﾄﾞｳﾒｯｾｰｼﾞ
int     endFG=0;                                        // 終了ﾌﾗｸﾞ

double  xS =-1.5;                                       // 実部 開始
double  xE = 1.5;                                       // 実部 終了
double  yS =-1.5;                                       // 虚部 開始
double  yE = 1.5;                                       // 虚部 終了
double  Cr =-0.3;                                       // 定数実部
double  Ci =-0.63;                                      // 定数虚部
double  imax=400;                                       // 回数精度
double  E   =4.0;                                       // 収束値

void  SETwindow(void);                                  // ｳｨﾝﾄﾞｳ初期設定
void  Display(void);                                    // 図形描画

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);      // ｳｨﾝﾄﾞｳﾌﾟﾛｼｰｼﾞｬ

void  main( )
{
    SETwindow( );                                       // ｳｨﾝﾄﾞｳ初期設定

    while ( 1 )
      {
        if ( PeekMessage(&msg,hWnd,0,0,PM_REMOVE)==0 )  // windowsﾒｯｾｰｼﾞ取得
             continue;                                  // ﾒｯｾｰｼﾞなし
        TranslateMessage(&msg);                         // ﾒｯｾｰｼﾞ変換
        DispatchMessage (&msg);                         // ﾒｯｾｰｼﾞ送出
        if ( endFG!=0 ) break;
      }

    DestroyWindow(hWnd);                                // ｳｨﾝﾄﾞｳ破棄
}


void  SETwindow( )
/*------------------------*/
/*  ウィンドウ  初期設定  */
/*------------------------*/
{
  WNDCLASS  wc;        // ｳｨﾝﾄﾞｳ ｸﾗｽ
  DWORD     Wstyle;    // ｳｨﾝﾄﾞｳ･ｽﾀｲﾙ

    //--ｳｨﾝﾄﾞｳｸﾗｽ--
    wc.lpszClassName="ジュリア集合";                    // ｳｨﾝﾄﾞｳ･ｸﾗｽ名
    wc.lpszMenuName =NULL;                              // ｸﾗｽ･ﾒﾆｭｰ･ﾘｿｰｽ名
    wc.hInstance    =GetModuleHandle(NULL);             // ｲﾝｽﾀﾝｽ･ﾊﾝﾄﾞﾙ
    wc.lpfnWndProc  =WndProc;                           // ｳｨﾝﾄﾞｳ･ﾌﾟﾛｼｰｼﾞｬ
    wc.hCursor      =LoadCursor(NULL,IDC_ARROW);        // ｸﾗｽ･ｶｰｿﾙ
    wc.hIcon        =NULL;                              // ｸﾗｽ･ｱｲｺﾝ
    wc.hbrBackground=GetStockObject(WHITE_BRUSH);       // ｸﾗｽ背景ﾌﾞﾗｼ
    wc.style        =CS_OWNDC|                          // ｸﾗｽ･ｽﾀｲﾙ
                     CS_BYTEALIGNCLIENT|
                     CS_BYTEALIGNWINDOW;
    wc.cbClsExtra   =0;                                 // 補足ｸﾗｽ･ﾒﾓﾘ
    wc.cbWndExtra   =0;                                 // 補足ｳｨﾝﾄﾞｳ･ﾒﾓﾘ

    RegisterClass(&wc);                                 // ｳｨﾝﾄﾞｳ･ｸﾗｽ登録

    //--ｳｨﾝﾄﾞｳ･ｽﾀｲﾙ--
    Wstyle= WS_OVERLAPPED|                              // 自動表示位置
            WS_SYSMENU|                                 // 閉じる可能
            WS_MINIMIZEBOX;                             // 最小化可

    //--ｳｨﾝﾄﾞｳ生成--
    hWnd=CreateWindow(wc.lpszClassName,                 // クラス名
                      wc.lpszClassName,                 // ｳｨﾝﾄﾞｳ名(実行ﾌｧｲﾙ)
                      Wstyle,                           // ｳｨﾝﾄﾞｳ･ｽﾀｲﾙ
                      0,                                // ｳｲﾝﾄﾞｳ水平位置
                      0,                                // ｳｲﾝﾄﾞｳ垂直位置
                      XMAX,                             // ｳｨﾝﾄﾞｳXｻｲｽﾞ(枠含む)
                      YMAX+18,                          // ｳｨﾝﾄﾞｳYｻｲｽﾞ(枠含む)
                      NULL,                             // 親ｳｨﾝﾄﾞｳ･ﾊﾝﾄﾞﾙ
                      NULL,                             // ﾒﾆｭｰﾊﾝﾄﾞﾙ
                      wc.hInstance,                     // ｱﾌﾟﾘｹｰｼｮﾝ･ｲﾝｽﾀﾝｽ･ﾊﾝﾄﾞﾙ
                      NULL);                            // ｳｨﾝﾄﾞｳ作成ﾃﾞｰﾀ

    ShowWindow(hWnd,SW_SHOWDEFAULT);                    // ｳｨﾝﾄﾞｳ表示状態設定
}


void  Display( )
/*----------------------------------*/
/*  ジュリア集合  図形描画          */
/*                                  */
/*  漸化式が発散するまでの計算回数  */
/*  によって、対応する画素の階調を  */
/*  を求め、画面に描画する          */
/*  画素は 0～255 のグレースケール  */
/*----------------------------------*/
{
  HDC     hdc;      // ﾃﾞﾊﾞｲｽｺﾝﾃｷｽﾄ ﾊﾝﾄﾞﾙ
  double  dx,dy;
  double  x0,y0,x,y,xN,yN;
  int     i,j,ix,iy,k,cl,nc;
  char    c[128];

    dx=(xE-xS)/XMAX;                                    // 実部刻み幅
    dy=(yE-yS)/YMAX;                                    // 虚部刻み幅
    nc=imax/256; if ( nc<=0 ) nc=1;                     // 階調比率(256階調)

    hdc=GetDC(hWnd);                                    // ｳｨﾝﾄﾞｳのDC取得

    for( y0=yS,i=0,iy=YMAX; i<YMAX; y0+=dy,i++,iy-- )
      {
        for( x0=xS,j=0,ix=0; j<XMAX; x0+=dx,j++,ix++ )
          {
            y=y0; x=x0;

            //--収束検査--
            for ( k=1; k<=imax; k++ )
              {
                xN=x*x-y*y+Cr;                          // 実部x*x-y*y+Cr
                yN=2*x*y+Ci;                            // 虚部2･x･y+Ci
                if ( xN*xN+yN*yN>E ) break;             // 収束しない

                x=xN; y=yN;
              }

            cl=k/nc;                                    // 階調計算
            if ( cl>255 ) cl=255;                       // 階調補正
            SetPixelV(hdc,ix,iy,RGB(cl,cl,cl));         // ｶﾗｰ値で点を描画
          }
      }

    sprintf(c,"Cr:%8.5lf  Ci:%8.5lf",Cr,Ci);
    TextOut(hdc,0,0,c,strlen(c));                       // 文字列描画

    ReleaseDC(hWnd,hdc);                                // ｳｨﾝﾄﾞｳのDC 解放
}


LRESULT CALLBACK  WndProc(
/*---------------------------*/
/*  ウィンドウ プロシージャ  */
/*---------------------------*/
HWND     hwnd,      // ｳｨﾝﾄﾞｳ･ﾊﾝﾄﾞﾙ
UINT     uMsg,      // ﾒｯｾｰｼﾞID
WPARAM   wParam,    // 第1ﾒｯｾｰｼﾞ･ﾊﾟﾗﾒｰﾀ(無符号)
LPARAM   lParam)    // 第2ﾒｯｾｰｼﾞ･ﾊﾟﾗﾒｰﾀ(有符号)
{
  PAINTSTRUCT hpaint;    // 描画情報
  BOOL        ir=0;

    switch ( uMsg )
      {
        case WM_CLOSE://--ｳｨﾝﾄﾞｳ閉--
                PostQuitMessage(0);                     // 実行を終了
                endFG=1;
                break;

        case WM_PAINT://--ｳｨﾝﾄﾞｳ更新--
        case WM_SETFOCUS://--ﾌｫｰｶｽ取得--
                if ( GetUpdateRect(hWnd,NULL,FALSE)==NULL )
                     break;                             // 更新ﾘｰｼﾞｮﾝなし
                BeginPaint(hWnd,&hpaint);
                Display( );                             // 図形描画
                EndPaint(hWnd,&hpaint);
                break;

        default://--その他--
                ir=DefWindowProc(hwnd,uMsg,wParam,lParam);
      }

    return(ir);
}
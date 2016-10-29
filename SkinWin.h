/*
	SkinWin skinning library for Windows XP/Vista/7  (c) by Michael Haensle 2012

		skinwin.de.to
		mikehaensle@yahoo.com
*/

#ifndef SKINWIN_DLL
#define SKINWIN_DLL

#ifdef __cplusplus
extern "C" {
#endif

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else
# define DLLIMPORT __declspec (dllimport)
#endif
                                  

/************************* SkinWin functions *************************/
int DLLIMPORT SkinWin_Start(const char *strSkinFile);
	/* Init SkinWin with a skin file.
	   If the function succeeds, the return value is 1. If the function fails, the return value is 0. */

int DLLIMPORT SkinWin_LoadSkin(const char *strSkinFile);
	/* Load a new skin file.
	   If the function succeeds, the return value is 1. If the function fails, the return value is 0. */

int DLLIMPORT SkinWin_SkinWindow(HWND hWnd, bool SkinIt);
    /* Set the skin mode for a window.
            bool SkinIt = true      the window is to skin
                        = false     the window is not to skin
       If the function succeeds, the return value is 1. If the function fails, the return value is 0. */

int DLLIMPORT SkinWin_AddClass(const char *strNewClass);
    /*  Add a new window class to the window skin list.
        When you create a child window within a top-level window, you can use this
        function to add the new class name of the child. This function is not important
        for top-level windows!
        If the function succeeds, the return value is 1, else 0. */

int DLLIMPORT SkinWin_Stop();
	/* Exit SkinWin.
	   If the function succeeds, the return value is 1. If the function fails, the return value is 0. */


/************************* SkinWin color messages *************************/
/* You must send a RGB code:  SendMessage(hWnd, one_of_the_messages_below, 0, RGB(255,255,255); */

/* Tabcontrol */
#define SKINWIN_WM_TAB_TEXTCOLOR	WM_USER + 255   /* send to set the textcolor for a tabcontrol */
#define SKINWIN_WM_TAB_BACKGROUND	WM_USER + 256   /* send to set the tab background for a tabcontrol */
#define SKINWIN_WM_TAB_IS_RAISED	WM_USER + 2567  /* set the border of the tabcontrol raised (true) or */
                                                    /* sunken (false) */
                                                    /* SendMessage(hWnd, SKINWIN_WM_TAB_IS_RAISED, 0, false); */
/* Radiobutton and Checkbox */
#define SKINWIN_WM_BUTTON_TEXTCOLOR	WM_USER + 257   /* send to set the textcolor for a radiobutton or checkbox */
/* Combobox */
#define SKINWIN_WM_COMBO_TEXTCOLOR	WM_USER + 258   /* send to set the textcolor for a combobox */
#define SKINWIN_WM_COMBO_BACKGROUND WM_USER + 2589  /* send to set the background color for a combobox */
/* Trackbar thumb and channel color */
#define SKINWIN_WM_TRACKBAR_THUMB	WM_USER + 259   /* send to set the thumb color for a trackbar */
#define SKINWIN_WM_TRACKBAR_CHANNEL	WM_USER + 260   /* send to set the channel color for a trackbar */
/* Groupbox */
#define SKINWIN_WM_GROUPBOX_TEXT	WM_USER + 260   /* send to set the textcolor for a groupbox */

#ifdef __cplusplus
}
#endif

#endif /* SKINWIN_DLL */

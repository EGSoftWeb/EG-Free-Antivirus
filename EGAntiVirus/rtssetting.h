#ifndef RTS_SETTING_HEADER
#define RTS_SETTING_HEADER


#include <wx/wx.h>
#include "gxButton.h"

const wxString dirStr[] =
{
	wxT(" Desktop"),
	wxT(" Download"),
	wxT(" AppData"),
	wxT(""),
};

class RTSSetting : public wxDialog
{

public:

	RTSSetting(const wxString& title);
	void OnBtnApply(wxCommandEvent& event);
	void OnBtnCancel(wxCommandEvent& event);
	/*
	private:
	void OnClose(wxCloseEvent& event);
	DECLARE_EVENT_TABLE()
	*/
	wxPanel* m_Panel_All;
	wxPanel* m_Panel_Upper;
	wxPanel* m_Panel_Lower;
	wxPanel* m_Panel_Content;
	wxPanel* m_Panel_CheckBox;

	wxBoxSizer* m_SH_Upper;
	wxBoxSizer* m_SV_Content;
	wxBoxSizer* m_SV_CheckBox;
	wxBoxSizer* m_SH_Buttons;
	wxBoxSizer* m_SV_Upper;
	wxBoxSizer* m_SV_Lower;

	wxStaticText* m_st_content[11];
	wxStaticText* m_st_RemoveOrNot;
	wxCheckBox* m_cb_RemoveOrNot[10];
	MyWXRoundEdgeButton* m_Btn_Apply;
	MyWXRoundEdgeButton* m_Btn_Cancel;

};

// 4000
enum eBTN_ID51
{
	ID_APPLY_BTN=4000,
	ID_CANCEL_BTN,
};

#endif // !RTS_SETTING_HEADER


#include "rtssetting.h"
#include "avtheme.h"


/*
BEGIN_EVENT_TABLE(Cleaner, wxFrame)
EVT_CLOSE(Cleaner::OnClose)
END_EVENT_TABLE()
*/


RTSSetting::RTSSetting(const wxString& title) : wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600), EGAV_DIALOG_BORDER_STYLE)
{
	Connect(ID_APPLY_BTN, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RTSSetting::OnBtnApply));
	Connect(ID_CANCEL_BTN, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RTSSetting::OnBtnCancel));


	//Load size values

	m_Panel_All = new wxPanel(this);
	m_Panel_Upper = new wxPanel(m_Panel_All);
	m_Panel_Lower = new wxPanel(m_Panel_All);
	m_Panel_Content = new wxPanel(m_Panel_Upper);
	m_Panel_CheckBox = new wxPanel(m_Panel_Upper);

	//panel upper
	m_SV_Content = new wxBoxSizer(wxVERTICAL);
	m_st_content[0] = new wxStaticText(m_Panel_Content, -1, wxT("Folder Name"));
	m_st_content[0]->SetForegroundColour(EGAV_TEXT_COLOR_WHITE);
	m_st_content[0]->SetFont(EGAV_FONT_SMALL_ROMAN_NORMAL_BOLD);
	m_SV_Content->Add(m_st_content[0], 1, 0, 1);
	m_SV_Content->AddStretchSpacer();

	int s = sizeof(dirStr) / sizeof(dirStr[0]);

	for (size_t i = 1; i < s; i++)
	{
		m_st_content[i] = new wxStaticText(m_Panel_Content, -1, dirStr[i - 1]);
		m_st_content[i]->SetForegroundColour(EGAV_TEXT_COLOR_WHITE);
		m_st_content[i]->SetFont(EGAV_FONT_SMALL_ROMAN_NORMAL_NORMAL);
		m_SV_Content->Add(m_st_content[i], 1, 0, 1);
		m_SV_Content->AddStretchSpacer();
	}
	m_Panel_Content->SetSizer(m_SV_Content);

	m_SV_CheckBox = new wxBoxSizer(wxVERTICAL);
	m_st_RemoveOrNot = new wxStaticText(m_Panel_CheckBox, -1, wxT("Remove"));
	m_st_RemoveOrNot->SetFont(EGAV_FONT_SMALL_ROMAN_NORMAL_BOLD);
	m_st_RemoveOrNot->SetForegroundColour(EGAV_TEXT_COLOR_WHITE);
	m_SV_CheckBox->Add(m_st_RemoveOrNot, 1, 0, 1);
	m_SV_CheckBox->AddStretchSpacer();
	
	for (size_t k = 0; k < s; k++)
	{
		m_cb_RemoveOrNot[k] = new wxCheckBox(m_Panel_CheckBox, k+4002, wxT(""));
		m_cb_RemoveOrNot[k]->SetForegroundColour(EGAV_TEXT_COLOR_WHITE);
		m_SV_CheckBox->Add(m_cb_RemoveOrNot[k], 1, 0, 1);
		m_SV_CheckBox->AddStretchSpacer();
	}
	m_cb_RemoveOrNot[9] = new wxCheckBox(m_Panel_CheckBox, 5000, wxT(""));
	m_cb_RemoveOrNot[9]->SetForegroundColour(EGAV_TEXT_COLOR_WHITE);
	m_SV_CheckBox->Add(m_cb_RemoveOrNot[9], 1, 0, 1);
	m_Panel_CheckBox->SetSizer(m_SV_CheckBox);

	m_SH_Upper = new wxBoxSizer(wxHORIZONTAL);
	m_SH_Upper->Add(m_Panel_Content, 3, wxEXPAND | wxALL, 20);
	m_SH_Upper->Add(m_Panel_CheckBox, 1, wxEXPAND | wxALL, 20);
	m_Panel_Upper->SetSizer(m_SH_Upper);

	//panellower
	m_Btn_Apply = new MyWXRoundEdgeButton(m_Panel_Lower, ID_APPLY_BTN, wxT("Apply"), wxDefaultPosition, EGAV_BUTTON_SIZE_MID, EGAV_BUTTON_STYLE_NOBORDER);
	m_Btn_Cancel = new MyWXRoundEdgeButton(m_Panel_Lower, ID_CANCEL_BTN, wxT("Cancel"), wxDefaultPosition, EGAV_BUTTON_SIZE_MID, EGAV_BUTTON_STYLE_NOBORDER);

	m_SH_Buttons = new wxBoxSizer(wxHORIZONTAL);
	m_SH_Buttons->AddStretchSpacer();
	m_SH_Buttons->Add(m_Btn_Apply);
	m_SH_Buttons->AddStretchSpacer();
	m_SH_Buttons->Add(m_Btn_Cancel);
	m_SH_Buttons->AddStretchSpacer();

	m_Panel_Lower->SetSizer(m_SH_Buttons);

	m_SV_Lower = new wxBoxSizer(wxVERTICAL);
	m_SV_Lower->AddStretchSpacer();
	m_SV_Lower->Add(m_Panel_Upper, 5, wxEXPAND | wxALL, 5);
	m_SV_Lower->AddStretchSpacer();
	m_SV_Lower->Add(m_Panel_Lower, 1, wxEXPAND | wxALL, 5);
	m_SV_Lower->AddStretchSpacer();
	m_Panel_All->SetSizer(m_SV_Lower);

	SetBackgroundColour(EGAV_WINDOW_BACK_COLOR1);

	Centre();
	ShowModal();
}

void RTSSetting::OnBtnApply(wxCommandEvent& event)
{
	//
	//
	//

	event.Skip();
	Destroy();
}

void RTSSetting::OnBtnCancel(wxCommandEvent& event)
{
	event.Skip();
	Destroy();
}

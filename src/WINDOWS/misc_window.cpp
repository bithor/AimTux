#include "misc_window.h"

MiscWindow* misc_window = nullptr;

MiscWindow::MiscWindow (std::string title, Vector2D size, Vector2D position, Color backgroundColor)
	: Window::Window (title, size, position, backgroundColor)
{
	ts_bhop = new ToggleSwitch ("bhop", LOC (10, 10), 33, &Settings::BHop::enabled);
	AddComponent (ts_bhop);
	
	ts_autostrafe = new ToggleSwitch ("auto strafe", BELOW (ts_bhop), 33, &Settings::AutoStrafe::enabled);
	AddComponent (ts_autostrafe);
	
	ts_spammer = new ToggleSwitch ("chat spammer", BELOW (ts_autostrafe), 33, &Settings::Spammer::NormalSpammer::enabled);
	AddComponent (ts_spammer);
	
	ts_spammer_kill = new ToggleSwitch ("kill spammer", STACK (ts_spammer), 33, &Settings::Spammer::KillSpammer::enabled);
	AddComponent (ts_spammer_kill);

	ts_airstuck = new ToggleSwitch ("airstuck", BELOW (ts_spammer), 33, &Settings::Airstuck::enabled);
	AddComponent (ts_airstuck);

	ts_showranks = new ToggleSwitch ("show ranks", BELOW (ts_airstuck), 33, &Settings::ShowRanks::enabled);
	AddComponent (ts_showranks);

	ts_showspectators = new ToggleSwitch ("show spectators", STACK (ts_showranks), 33, &Settings::ShowSpectators::enabled);
	AddComponent (ts_showspectators);

	ts_noflash_enabled = new ToggleSwitch ("no flash", BELOW (ts_showranks), 33, &Settings::Noflash::enabled);
	AddComponent (ts_noflash_enabled);
	
	sl_noflash_value = new Slider ("", STACK (ts_noflash_enabled), LOC (size.x - ts_noflash_enabled->size.x - 30, 33), &Settings::Noflash::value, 0.0f, 255.0f);
	AddComponent (sl_noflash_value);
	
	tb_clantag = new TextBox ("clantag", Settings::ClanTagChanger::value, BELOW (ts_noflash_enabled), LOC (270, 30));
	AddComponent (tb_clantag);
	
	ob_clantag_set = new OutlinedButton ("set clan tag", STACK (tb_clantag), LOC (110, 30));
	AddComponent (ob_clantag_set);
	ob_clantag_set->OnClickedEvent = MFUNC (&MiscWindow::SetClanTag, this);
	
	ts_clantag_animation = new ToggleSwitch ("clantag animation", BELOW (tb_clantag), 33, &Settings::ClanTagChanger::animation);
	AddComponent (ts_clantag_animation);
	
	Hide ();
}

void MiscWindow::SetClanTag ()
{
	std::string text = Util::ReplaceString(tb_clantag->text, "\\n", "\n");
	Settings::ClanTagChanger::value = strdup(text.c_str());
}

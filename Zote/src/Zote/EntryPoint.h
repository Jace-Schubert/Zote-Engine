#pragma once

#ifdef ZT_PLATFORM_WINDOWS
	extern Zote::App* Zote::CreateApp();

	int main(int argc, char** argv)
	{
		Zote::Log::Init();
		
		Zote::App* app = Zote::CreateApp();
		app->Run();
		delete app;
	}
#endif
#pragma once
#include "Core.h"

namespace Zote
{
	class ZOTE_API App
	{
	public:
		App();
		virtual ~App();

		void Run();
	};

	App* CreateApp();
}


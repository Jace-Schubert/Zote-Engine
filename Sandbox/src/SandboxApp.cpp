#include <Zote.h>

class Sandbox : public Zote::App
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Zote::App* Zote::CreateApp()
{
	return new Sandbox();
}
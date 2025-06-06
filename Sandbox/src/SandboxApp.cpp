#include <Zote.h>

class SandboxLayer : public Zote::Layer
{
	void OnEvent(Zote::Event& event) override
	{
		std::cout << "Event Occured!\n";
	}
};

class Sandbox : public Zote::App
{
public:
	Sandbox()
	{
		PushLayer(new SandboxLayer());
	}
	~Sandbox()
	{
	}
};

Zote::App* Zote::CreateApp()
{
	return new Sandbox();
}
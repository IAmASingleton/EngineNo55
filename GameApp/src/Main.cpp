#include <EngineNo55.h>

class SandBox : public Number55::Application
{
public: 
	SandBox() {}
	~SandBox() {}

};

Number55::Application* Number55::CreateApplication()
{
	return new SandBox();
}
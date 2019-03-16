#include <iostream>

#include "vrpn_Button.h"
#include "vrpn_Analog.h"
#include <windows.h>
#include <Python.h>
 
void VRPN_CALLBACK vrpn_button_callback(void* user_data, vrpn_BUTTONCB button)
{
	std::cout << "Button ID : " << button.button << " / Button State : " << button.state << std::endl;

	if (button.button == 1)
	{
		*(bool*)user_data = false;
	}
} 
 


void VRPN_CALLBACK vrpn_analog_callback(void* user_data, vrpn_ANALOGCB analog)
{
	
	std::cout << "Analog Channel : " << 0 << " / Analog Value : " << analog.channel[0] << std::endl;
	std::cout << "Analog Channel : " << 1 << " / Analog Value : " << analog.channel[1] << std::endl;

	if (analog.channel[0]>0.5) {
			
		Py_Initialize();
		PyObject* PyFileObject = PyFile_FromString("sendkey.py", "r");
		PyRun_SimpleFileEx(PyFile_AsFile(PyFileObject), "sendkey.py", 1);
		Py_Finalize();
			
	}

	
}    

int main(int argc, char** argv)
{
	//CSendKeys sk;
	/* flag used to stop the program execution */
 	bool running = true;

	/* VRPN Button object */
	vrpn_Button_Remote* VRPNButton;

	/* Binding of the VRPN Button to a callback */
	VRPNButton = new vrpn_Button_Remote("openvibe-vrpn1@localhost");
	VRPNButton->register_change_handler(&running, vrpn_button_callback);


	/* VRPN Analog object */
	vrpn_Analog_Remote* VRPNAnalog;

	/* Binding of the VRPN Analog to a callback */
	VRPNAnalog = new vrpn_Analog_Remote("openvibe-vrpn1@localhost");
	VRPNAnalog->register_change_handler(NULL, vrpn_analog_callback);

	/* The main loop of the program, each VRPN object must be called in order to process data */
	while (running)
	{
		VRPNButton->mainloop();
	}

	return 0;

	 
}
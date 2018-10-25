#include "pch.h"
#include "sendData.h"
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>

//UWP namespaces
using namespace Windows::Foundation;
using namespace Windows::Web::Http;

//VARS to manage the amount of data sent  
int sentLast = 10;
int sendVal = 20;

//SENDS data on the eyes and jaw every SendVal iterations starting halfway through sendVal
void sendData(bool eye, bool jaw)
{
	//increment sentLast
	sentLast++;
	
	//if its okay to send
	if (sentLast>=sendVal) {
		//open a http client at raspberrypi.local (got from Bonjour) with the values of eye and jaw
		auto uri = ref new Uri("http://raspberrypi.local/webdrive.php?eye=" + eye + "&jaw=" + jaw);
		// raspberrypi.local requires mDNS, i.e. Bonjour
		auto httpClient = ref new HttpClient();

		//send the values
		httpClient->GetStringAsync(uri);
		//start counting to the next sendVal over again
		sentLast = 0;
	}
}

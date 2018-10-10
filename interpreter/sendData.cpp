#include "pch.h"
#include "sendData.h"
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>

using namespace Windows::Foundation;
using namespace Windows::Web::Http;

int sentLast = 10;
int sendVal = 20;
void sendData(bool eye, bool jaw)
{
	sentLast++;
	if (sentLast>=sendVal) {
		auto uri = ref new Uri("http://raspberrypi.local/webdrive.php?eye=" + eye + "&jaw=" + jaw); // raspberrypi.local requires mDNS, i.e. Bonjour
		auto httpClient = ref new HttpClient();

		httpClient->GetStringAsync(uri);
		sentLast = 0;
	}
}

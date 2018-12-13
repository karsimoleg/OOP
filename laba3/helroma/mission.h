
int getCurrentMission(int x)
{
	int mission = 0;
	if ((x>0) && (x<400)) { mission = 0; } 
	if (x>400) { mission = 1; } 
	if (x>700) { mission = 2; }
	if (x>2200) { mission = 3; }

	return mission;
}




std::string getTextMission(int currentMission) {

	std::string missionText = "";
	
	switch (currentMission)
	{
	case 0: missionText = "black icon -40\nred icon +20\nflower 0\n"; break;
	case 1: missionText = ""; break;
	case 2: missionText = ""; break;
	case 3: missionText = ""; break;
	}

	return missionText;
};
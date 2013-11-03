#if !defined(_IMAGE_PATH_CONSTANTS)
#define _IMAGE_PATH_CONSTANTS

#include <string>

namespace Constants
{
	const std::string imagePath("images/");

	//Map View Manager
	const std::string imageLandPath( imagePath + "land.jpg" );
	const std::string imageSandPath( imagePath + "sand.jpg" );
	const std::string imageWaterPath( imagePath + "water.jpg" );

	//Splash Screen Manager
	const std::string imageSplashScreen( imagePath + "splash.jpg" );
}

#endif
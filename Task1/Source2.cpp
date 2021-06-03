#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>

#pragma comment(lib, "urlmon.lib")

using namespace std;

void downloadOnThread(const string URI, const string path, const string filename) {
	string downloadURL = URI;
	string savepath = path+filename;
	//windows utility to download the images
	URLDownloadToFile(NULL, downloadURL.c_str(), savepath.c_str(), 0, NULL);
}

int main() {

	//progress bar
	int progress = 0;
	//total number of images
	const int totalImg = 3;

	const string firstImage = "https://ichef.bbci.co.uk/news/976/cpsprodpb/313F/production/_114270621_mainimage.jpg";
	const string secondImage = "https://honeydoze.com/wp-content/uploads/2019/03/InfinityWar5aabd55fed5fa.jpg";
	const string thirdImage = "https://static.wikia.nocookie.net/marvelcinematicuniverse/images/d/d0/Theavengersnewposter.jpg/revision/latest/scale-to-width-down/337?cb=20140224212619";
	//this is a directory to which downloaded images will be stored
	const string dir_path = "E:\\Afiniti\\";
	//new names of downloaded images
	const string images[3] = { "Image_1.png" ,"Image_2.png" , "Image_3.png"};

	//function and its parameters are passed to download the images
	//and save them to a designated location

	//thread 1
	thread t1 { downloadOnThread , firstImage, dir_path, images[0] };
	//thread 2
	thread t2 { downloadOnThread , secondImage, dir_path, images[1] };
	//thread 3
	thread t3 { downloadOnThread , thirdImage, dir_path, images[2] };
	

	//this while loop is used insdie main thread to find if t1,t2,t3 threads
	//are joinable or not, if they are joinable then it means they have finished
	//their job then we increment the progress by 1 whenever each thread becomes
	//joinable
	int key1 =0, key2=0, key3 = 0;
	while (1) {
		cout << "Download Progress : " << 100*(progress / totalImg) << endl;
		if (t1.joinable() && !key1) {
			progress++;
			key1 = 1;
		}
		cout << "Download Progress : " << 100 * (progress / totalImg) << endl;
		if (t2.joinable() && !key2) {
			progress++;
			key2 = 1;
		}
		cout << "Download Progress : " << 100 * (progress / totalImg) << endl;
		if (t3.joinable() && !key3) {
			progress++;
			key3 = 1;
		}
		cout << "Download Progress : " << 100 * (progress / totalImg) << endl;
		//when all threads are joined then this while loop would break
		if (progress == totalImg) {
			break;
		}
	}

	t1.join();

	t2.join();

	t3.join();


	return 0;
}

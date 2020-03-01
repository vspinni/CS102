//Author: Shravan Pinni
//Date: 11/10/18
//Lab 12

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//Struct for Pixel with positive only red, green, and blue values
struct Pixel{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
};

//Class Picture with private variables and vectors and public functions
class Picture {

	private: 
		vector <Pixel> Pixels;
		int width;
		int height;
		int maxIntensity;

	public:
		Picture();
		const Pixel& get_pixel(int row, int column) const;
		Pixel& get_pixel(int row , int column);
		void set_pixel(int row, int column, const Pixel& );
		void invert();
		void flip_x();
		void flip_y();
		bool read_input(istream &in);
		void write_output(ostream &out);
};


int main (int argc, char* argv[]){
	Picture pic;
	//if the argc count is not 4 or three, tells the user that the format is incorrect and ends the run
	if (!(argc==4||argc==3)){
		cout << "Incorrect Format. Proper format: <input file or '-'> <output file or '-'> <I/X/Y/not specified>\n";
		return 1;
	}
	
	string input = argv[1];
	//processes read_input using cin if a dash is entered as the argv[1]
	if(input == "-"){
	pic.read_input(cin);	
	}



	return 0;

}
//default constructor for Picture
Picture:: Picture(){
	width = 0;
	height = 0;
	maxIntensity = 0;
};
//accessor for get_pixel
const Pixel& Picture:: get_pixel(int row, int column) const {
	return Pixels.at((row*width)+column);
}
//mutator for get_pixel
Pixel& Picture:: get_pixel(int row, int column){
	return Pixels.at((row*width)+column);
}
//set_pixel which uses the mutator get_pixel to set a particular pixel equal to a given pixel
void Picture:: set_pixel(int row, int column, const Pixel& pix){
	get_pixel(row, column) = pix;
}
//inverts a given image by setting the rgb values of each pixel to the maxIntensity-currentValue
void Picture:: invert(){
	
	for(int i = 0;i<width;i++){
		for(int j = 0;j<height;j++){
			Pixel tempPix;
			tempPix.red = maxIntensity-get_pixel(i,j).red;
			tempPix.green = maxIntensity-get_pixel(i,j).green;
			tempPix.blue = maxIntensity-get_pixel(i,j).blue;
			set_pixel(i,j,tempPix);
		}
	}
}
//flips a given image over the x axis
void Picture:: flip_x(){
	Pixel temp;
	for(int i = 0;i<width/2;i++){
		for(int j = 0;j<height;j++){
			temp = get_pixel(i,j);
			set_pixel(i,j,get_pixel(width-1-i,j));
			set_pixel(width-1-i,j,temp);
		}
	}
}

//Flips a given image over the y axis
void Picture:: flip_y(){
	Pixel temp;
	for(int i =0;i<width;i++){
		for(int j = 0;j<height/2;j++){
			temp = get_pixel(i,j);
			set_pixel(i,j,get_pixel(i,height-1-j));
			set_pixel(i,height-1-j,temp);
		}
	}
}

//reads the input to the pixel vector
bool Picture:: read_input(istream &in){
	return true;
}
//writes the output to the output file
void Picture:: write_output(ostream &out){

}




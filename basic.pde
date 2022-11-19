//A basic example

import VLCJVideo.*;

VLCJVideo video;
String[] options = {"--hwdec=auto"};
int val =0;
void setup() {
  fullScreen();
  frameRate(30);
  video = new VLCJVideo(this,options);
println(dataPath(""));
video.openAndPlay(dataPath("")+"/Сохраняя будущее.mp4");
}

void draw() {
  background(0);
if (val != 0){
play();
}
if(video.isStopped()) {
video.openAndPlay(dataPath("")+"/Сохраняя будущее.mp4");
}
}

void play(){
  image(video, 0, 0, width, height);

}

void keyPressed() {
  if(key=='1'){
val = 1;
video.openAndPlay(dataPath("")+"/1.АЭРОКЛУБ.mp4");
  }
    if(key=='2'){
val = 2;
video.openAndPlay(dataPath("")+"/Вышка.mp4");
  }
      if(key=='3'){
val = 3;
video.openAndPlay(dataPath("")+"3.Домик Сели.mp4");
  }
      if(key=='4'){
val = 4;
video.openAndPlay(dataPath("")+"./Вышка.mp4");
  }
      if(key=='5'){
val = 5;
video.openAndPlay(dataPath("")+"./Вышка.mp4");
  }
      if(key=='6'){
val = 6;
video.openAndPlay(dataPath("")+"./Вышка.mp4");
  }
      if(key=='7'){
val = 7;
video.openAndPlay(dataPath("")+"./Вышка.mp4");
  }
      if(key=='8'){
val = 8;
video.openAndPlay(dataPath("")+"./Вышка.mp4");
  }
      if(key=='9'){
val = 9;
video.openAndPlay(dataPath("")+"./Вышка.mp4");
  }
      if(key=='0'){
val = 10;
video.openAndPlay(dataPath("")+"./Вышка.mp4");
  }
      if(key=='-'){
val = 10;
video.openAndPlay(dataPath("")+"./Вышка.mp4");
  }
}

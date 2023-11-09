#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "../../units.hpp"
#include "../../physics.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace sf;
using namespace unit;
using namespace Constants;

float scale              = 10.0f;
const float tennisMass   = 57.0f*kg; // in kg
const float tennisCx     = 0.57f;
const float tennisRadius = 0.033f*meter; //m 

const float petanqueMass   = 700*kg;
const float petanqueCx     = 0.45;
const float petanqueRadius = 0.037f*meter;

float width  = 800.0f;
float height = 800.0f;
float Zfall  = 7*meter;
bool paused  = true;
string pausedText = "Press Space to start the simulation and Tab to pause it";

void adjustOrigin(Text txt){
    FloatRect txtRect = txt.getLocalBounds();
    txt.setOrigin(txtRect.width/2, txtRect.height/2);
}

void setPropreties(Object &objectX, float mass, float Cx, float radius){
    objectX.mass   = mass;
    objectX.Cx     = Cx; 
    objectX.radius = radius;
    objectX.Surface = M_PI * pow(radius, 2);
}
int main(){
    VideoMode vm(width, height);
    RenderWindow window(vm, "Air Diving", Style::Default);
    Clock clock;
    Texture bgScreen;
    Texture tennisTexture;
    bgScreen.loadFromFile("Textures/bg.jpg");
    tennisTexture.loadFromFile("Textures/tennisBall.jpg", IntRect(0, 0, width, height));

    Sprite bgSprite;
    bgSprite.setTexture(bgScreen);
    Object tennisObject;
    Object petanqueObject;
    setPropreties(tennisObject, tennisMass, tennisCx, tennisRadius);
    setPropreties(petanqueObject, petanqueMass, petanqueCx, petanqueRadius);

    float ballTenisPos    = 0;
    float ballPetanquePos = 0; 
    float ballPetanqueXpos = width - 2*petanqueObject.radius*mm;
    CircleShape tennisBall;
    CircleShape petanqueBall;
    tennisBall.setRadius(tennisObject.radius*mm);
    tennisBall.setTexture(&tennisTexture);
    tennisBall.setPosition(0, ballTenisPos);

    petanqueBall.setRadius(petanqueObject.radius*mm);
    petanqueBall.setPosition(ballPetanqueXpos, ballPetanquePos);
    petanqueBall.setFillColor(Color::Black);

    float V0Tennis = getV0(tennisObject.mass, tennisObject.Cx, tennisObject.Surface);
    float Ttennis  = getT(V0Tennis);
    float tmaxTenis = Ttennis * acoshf(expf(Zfall/(V0Tennis * Ttennis)));
    float tenisTime = 0.0f;

    float V0petanque = getV0(petanqueObject.mass, petanqueObject.Cx, petanqueObject.Surface);
    float Tpetanque  = getT(V0petanque);
    float tmaxPetanque = Tpetanque * acoshf(expf(Zfall / (V0petanque * Tpetanque)));
    float petanqeTime = 0.0f;

    Text textpaused;
    Text Time1, Time2;
    Font font;
    Time1.setFont(font);
    Time1.setCharacterSize(30);
    Time1.setFillColor(Color::Red);
    Time1.setString("Time = " + to_string(tenisTime));
    Time1.setPosition(100, 0);
    Time2.setFont(font);
    Time2.setCharacterSize(30);
    Time2.setFillColor(Color::Red);
    Time2.setString("Time =" + to_string(petanqeTime));
    Time2.setPosition(500, 0);
    if (!font.loadFromFile("/Library/Fonts/Arial Unicode.ttf")) return 1;
    textpaused.setCharacterSize(30);
    textpaused.setFont(font);
    textpaused.setFillColor(Color::Red);
    textpaused.setString(pausedText);
    
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asMicroseconds();
        Event event;
        if (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)){
            if (paused){
                paused = false;

            }
        }
        if (!paused){
            if (tenisTime < tmaxTenis){
                ballTenisPos = (V0Tennis*Ttennis*log(coshf(tenisTime / Ttennis))*mm) / scale;
                tenisTime += deltaTime /11000000;
            if (petanqeTime < tmaxPetanque){
                ballPetanquePos = (V0petanque*Tpetanque*log(coshf(petanqeTime / Tpetanque))*mm) / scale;
                petanqeTime += deltaTime /11000000;
            }
            }if (tenisTime >= tmaxTenis && petanqeTime >= tmaxPetanque){
                paused = true;
                tenisTime = 0;
                petanqeTime = 0;
            }
            
            tennisBall.setPosition(0, ballTenisPos);
            petanqueBall.setPosition(ballPetanqueXpos, ballPetanquePos);
        }
        window.clear();
        window.draw(bgSprite);
        window.draw(tennisBall);
        window.draw(petanqueBall);
        if (paused) {
            adjustOrigin(textpaused);
            textpaused.setPosition(width/2.0f -textpaused.getLocalBounds().width/2.0, height/2.0);
            window.draw(textpaused);
        }else{
            Time1.setString("Time = " + to_string(tenisTime));
            Time2.setString("Time = " + to_string(petanqeTime));
        }
        window.draw(Time1);
        window.draw(Time2);
        window.display();
    }
    
    return 0;
}
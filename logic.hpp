#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hopper{
    private:
        int maxBeans;
        int minBeans;
    public:
        Hopper() {
            maxBeans = 200;
        }
        int Add(int g) {
            if (g > minBeans){
                cout << "Not that many beans" << endl;
                return 0;
            }
            minBeans -= g;
            return g;
        }
        void AddBeans(int g) {
            if ((g + this->minBeans) > this->maxBeans){
                cout << "Only 200 beans" << endl;
                this->minBeans = 200;
            }
            else{
                this->minBeans += g;
                cout << this->minBeans << " are now available" << endl;
            }
        }
};

class WaterReservoir{
    private:
        int minWater;
        int maxWater;
        int waterTemp;
    public:
        WaterReservoir() {
            minWater = 0;
            maxWater = 1;
            waterTemp = 30;
        }
        void TemperatureChange(const int t){
            cout << "Temperature is now " << t << "degrees C" << endl;
            waterTemp = t;
        }
        void IncreaseWater(const int L){
            if (L > maxWater){
                cout << "1 liter was added" << endl;
                this->TemperatureChange(30);
            }
            else{
                minWater += L;
                cout << this->minWater << " of water is added" << endl;
                this->TemperatureChange(30);
            }
        }
        bool PourWater(){
            if (minWater < 0.25){
                cout << "Not enough water" << endl;
                return false;
            }
            else if (waterTemp < 100){
                cout << "Not hot enough" << endl;
                return false;
            }
            cout << ".25 liters of hot water" << endl;
            return true;
        }
};

class HeatSource{
    public:
        HeatSource(){
        }
        void HeatUp(WaterReservoir *wr){
            wr->TemperatureChange(100);
            cout << "Water increased to 100 degrees" << endl;
        }
};

class Grinder{
    public:
        bool Grind(Hopper *h){
            int Grinded = h->Add(50);
            if (Grinded < 50){
                cout << "Less than 50 g" << endl;
                return false;
            }
            cout << "50 g produced" << endl;
            return true;
        }
};

class CupReceptable{
    public:
        bool PourAll(Grinder *g, HeatSource *hs, WaterReservoir *wr, CupReceptable *cr, Hopper *h){
            if (g->Grind(h) && wr->PourWater()){
                cout << "Coffee complete" << endl;
                return true;
            }
            cout << "No coffee" << endl;
            return false;
        }
};

class Maker{
    public:
        Hopper *h;
        WaterReservoir *wr;
        HeatSource *hs;
        Grinder *g;
        CupReceptable *cr;
        Maker(){
            h = new Hopper();
            wr = new WaterReservoir();
            hs = new HeatSource();
            g = new Grinder();
            cr = new CupReceptable();
        }

        bool Request(const int i){
            if (i > 4){
                cout << "Please only select up to 4 cups" << endl;
                return false;
            }

            hs->HeatUp(wr);

            for (int j = 0; j < i; j++){
                if (cr->PourAll(g, hs, wr, cr, h)){
                    cout << j+1 << " cups poured" << endl;
                }
            }
            cout << "Enjoy!" << endl;
            return true;
        }
};

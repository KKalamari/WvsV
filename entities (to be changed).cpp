#include <vector>
#include <iostream>
#include <string>
#include <cstdlib> //γινεται χρηση srand και rand παρακατω
using namespace std;




class human {
private:
    int x, y;  //θα χρησιμοποιηθουν ως συντεταγμενες
public:
    human() {
        this->x = set_x();     // εισαγωγη τυχαιας τιμης συντεταγμενων μέσα στα όρια του εκαστοτε map
        this->y = set_y();  //προσεχης εισαγωγη για error-check (search,throw)
    }
   virtual int set_x() {
       this->x = rand() % 70;
       return this->x;
   }
   virtual int set_y() {
    
      this->y = rand() % 70 ;
      return this->y;
   }
    virtual int getX() const {
        return this->x;
    } 
    virtual int getY() const {
        return this->y;
    }
    
    virtual void move() {
        switch (1 + rand() % 4) {  // οι περιπτωσεις να μετακινηθει προς οποιαδήποτε κατευθυνση είναι ισοπίθανη
        case 1:
            this->x += 1;
            break;
        case 2:
            this->x -= 1;
            break;
        case 3:
            this->y += 1;
            break;
        case 4:
            this->y -= 1;
            break;
        default:
            break;
        }
    }
    virtual void printXY(human i) const {
        cout << "the x is: " << i.getX() << " and the y is:" << i.getY() << endl;
   }
    //virtual void attack();
       
}; 




class vampire : public human {
private:
  int  stats[3],x,y;  //πινακα στα stats me 3 στοιχεια (power,defense,health) για να κανει return και τα 2 με μια μονο συναρτηση.
public:
    vampire() {
        this->x = set_x();
        this->y = set_y();
        stats[0] = 1 + rand() % 3;
        stats[1] = 1+rand()%2;
        stats[2] = 1 + rand() % 10;
    }
    
    int getstats(short int x) const;
    void printstats(vampire) const;
   // void attack() {
        
  // }
    int getX() const; 
    int getY() const;
};

int vampire::getstats(short int x) const {   
    return *(stats+x);
}

void vampire::printstats(vampire i ) const {
    cout << "the power, the defense and the health are:" << i.getstats(0)<<","<<i.getstats(1)<< ","<<i.getstats(2); // 0->επιστρεφει power, 1->επιστρεφει defense, 2->επισρεφει health
}

int vampire::getX() const {

    return this->x;
}

int vampire::getY() const {
    return this->y;
}


class warewolf :public vampire{
private:
    int stats[3],x,y;
public:
    warewolf() {
        srand(time(0));
        this->x = rand() % 70;     
        this->y = rand() % 70;
        stats[0] = 1 + rand() % 3;
       this->stats[1] = 1 + rand() % 2;
        this->stats[2] = 1 + rand() % 10;
    }
  
};


int main() {
   human isidoros;
   cout <<"the x is : " << isidoros.getX()<<"  and the y is : "<<isidoros.getY()<< endl;
   // isidoros.move() ;
   // cout <<"the x is:"<< isidoros.getX() << "  and the y is : " << isidoros.getY() <<endl;
    
    vampire kyriaki;
  //  kyriaki.print(kyriaki);
    cout << "the x is:" << kyriaki.getX() << " and the y is:" << kyriaki.getY() << endl;
   // kyriaki.printXY(kyriaki);
  
    
}

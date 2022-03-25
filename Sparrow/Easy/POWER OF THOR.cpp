#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();
    int curX= initial_tx;  int curY =initial_ty; string ans ; 
    // game loop
    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns; cin.ignore();
        if (curX > light_x && curY > light_y ) {  
            curX= curX-1; curY= curY-1; 
            ans= "NW"; 
        }
        else if (curX > light_x && curY < light_y ) {  
            curX= curX-1; curY= curY+1; 
            ans= "SW"; 
        }
        else if (curX < light_x && curY < light_y ) {  
            curX= curX+1; curY= curY+1; 
            ans= "SE"; 
        }
        else if (curX < light_x && curY > light_y ) {  
            curX= curX+1; curY= curY-1; 
            ans= "NE"; 
        }
        else if ( curX > light_x) { 
            curX -=1 ; 
            ans = "W";
        }
        else if ( curX < light_x) { 
            curX +=1 ; 
            ans = "E";
        }
        else if ( curY > light_y) { 
            curY -=1 ; 
            ans = "N";
        }
        else if ( curY < light_y) { 
            curY +=1 ; 
            ans = "S";
        }
        cout<<ans<<endl;; 
    }
}

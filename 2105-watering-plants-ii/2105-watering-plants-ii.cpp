class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i=0 ; int j = plants.size()-1 ;
        int capA = capacityA ;
        int capB = capacityB ;

        int refills = 0 ;

        while(i <= j){
            if(i == j){
                if(capA >= capB){
                    if(capA < plants[i]){
                        refills++ ;
                        break ;
                    }else break ;
                }else{
                    if(capB < plants[j]){
                        refills++ ;
                        break ;
                    }else break ;
                }
            }

            if(capA < plants[i]){
                refills++ ;
                capA = capacityA ;
                capA -= plants[i] ;
                i++ ;
            }else{
                capA -= plants[i] ;
                i++ ;
            }

            if(capB < plants[j]){
                refills++ ;
                capB = capacityB ;
                capB -= plants[j] ;
                j--;
            }else{
                capB -= plants[j] ;
                j-- ;
            }
        }
        return refills ;
    }
};
#include <iostream>

int main(){
    int cnt; 
        std::cin>>cnt;
        for(int i=0;i<cnt;++i){
                int legCnt = 0;
                        std::cin>>legCnt;
                        if(legCnt & 0x1){
                                    std::cout <<0 <<" "<<0<<std::endl;
                                            
                        }else{
                                    int cntMin= legCnt>>2 + legCnt&0x2 ? 1 :0;
                                                int cntMax = legCnt>>1;
                                                            std::cout << cntMin<<" " << cntMax<<std::endl;
                                                                    
                        }
                            
        }

}

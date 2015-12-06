//
//  UV.cpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2015/12/06.
//
//
#define K 3.0
#define M 5.0
#define OMEGA sqrt(K/M)

class UV{
public:
    double u = 0;
    double v = 0;
    
    UV getDY_DT(){
        UV dy_dt;
        dy_dt.u = this->v;
        dy_dt.v = -(K/M)* this->u;
        return dy_dt;
    }
    
    UV operator * (double amp){
        UV uv;
        uv.u = this->u * amp;
        uv.v = this->v * amp;
        return uv;
    }
    
    UV operator + (UV uv0){
        UV uv;
        uv.u = this->u + uv0.u;
        uv.v = this->v + uv0.v;
        return uv;
    }
    
    void operator = (UV newUV){
        this->u = newUV.u;
        this->v = newUV.v;
    }
};
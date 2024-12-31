#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <chrono>
#include <ctime>  
using namespace std;

//CLASSES VECTOR3 AND SPHERE
class Vector3{
    public:
        Vector3();
        Vector3(double posX, double posY, double posZ);
        ~Vector3();
        void setX(double newX);
        void setY(double newY);
        void setZ(double newZ);
        double getX();
        double getY();
        double getZ();
        
        Vector3 subtract(Vector3 p2);
        void minus(Vector3 p2);
        
        Vector3 add(Vector3 p2);
        void plus(Vector3 p2);

        Vector3 mul(double num);
        void times(double num);

        Vector3 cross(Vector3 p2);
        double dot(Vector3 p2);

        double distance(Vector3 p2);
        double magnitude();
        
        Vector3 normalized();
        void normalize();

        void print_vec();
        void clamp(double min, double max);

    private:
        double x;
        double y;
        double z;
};

Vector3::Vector3(){
    x = -1;
    y = -1;
    z = -1;
};

Vector3::Vector3(double posX, double posY, double posZ){
    x = posX;
    y = posY;
    z = posZ;
};

Vector3::~Vector3(){};

void Vector3::setX(double newX){x = newX;};

void Vector3::setY(double newY){y = newY;};

void Vector3::setZ(double newZ){z = newZ;};

double Vector3::getX(){return x;};

double Vector3::getY(){return y;};

double Vector3::getZ(){return z;};

Vector3 Vector3::subtract(Vector3 p2){
    Vector3 newVector;
    newVector.setX(x - p2.getX());
    newVector.setY(y - p2.getY());
    newVector.setZ(z - p2.getZ());

    return newVector;
};

void Vector3::minus(Vector3 p2){
    x = x - p2.getX();
    y = y - p2.getY();
    z = z - p2.getZ();
};

Vector3 Vector3::add(Vector3 p2){
    Vector3 newVector;
    newVector.setX(x + p2.getX());
    newVector.setY(y + p2.getY());
    newVector.setZ(z + p2.getZ());

    return newVector;
};

void Vector3::plus(Vector3 p2){
    x = x + p2.getX();
    y = y + p2.getY();
    z = z + p2.getZ();
};

Vector3 Vector3::mul(double num){
    Vector3 newVector;

    newVector.setX(x * num);
    newVector.setY(y * num);
    newVector.setZ(z * num);

    return newVector;
};

void Vector3::times(double num){
    x = x * num;
    y = y * num;
    z = z * num;
};

Vector3 Vector3::cross(Vector3 p2){
    Vector3 newVector;
    newVector.setX((y * p2.getZ()) - (z * p2.getY()));
    newVector.setY((z * p2.getX()) - (x * p2.getZ()));
    newVector.setZ((x * p2.getY()) - (y * p2.getX()));

    return newVector;
};

double Vector3::dot(Vector3 p2){
    return (x * p2.getX() + y * p2.getY() + z * p2.getZ());
};

double Vector3::distance(Vector3 p2){
    Vector3 newVector;
    newVector.setX(x - p2.getX());
    newVector.setY(y - p2.getY());
    newVector.setZ(z - p2.getZ());
    return newVector.magnitude();
};

double Vector3::magnitude(){
    return sqrt((x * x) + (y * y) + (z * z));
};

void Vector3::normalize(){
    double mag = sqrt((x * x) + (y * y) + (z * z));
    x = (x / mag);
    y = (y / mag);
    z = (z / mag);
};

Vector3 Vector3::normalized(){
    Vector3 newVector;
    double mag = sqrt((x * x) + (y * y) + (z * z));
    newVector.setX(x/mag);
    newVector.setY(y/mag);
    newVector.setZ(z/mag);
    return newVector;
};

void Vector3::print_vec(){
    cout << x << " " << y << " " << z << endl;
};

void Vector3::clamp(double min, double max){
    if(x < min){x = min;}
    else if(x > max){x = max;}

    if(y < min){y = min;}
    else if(y > max){y = max;}

    if(z < min){z = min;}
    else if(z > max){z = max;}
}

class Light{
    public:
        Light(Vector3 place, double intensity, double type);
        Vector3 getLightPlace();
        double getIntensity();
        double getLightType();
        void setAttLight(Vector3 cValues);
        Vector3 getAttLight();
    private:
        Vector3 lightPlacement;
        double lightIntensity;
        double lightType;
        Vector3 attLight;
};

Light::Light(Vector3 place, double intensity, double type){
    lightPlacement = place;
    lightIntensity = intensity;
    lightType = type;


};

Vector3 Light::getAttLight(){
    return attLight;
};

void Light::setAttLight(Vector3 cValues){
    attLight.setX(cValues.getX());
    attLight.setY(cValues.getY());
    attLight.setZ(cValues.getZ());
};

Vector3 Light::getLightPlace(){
    return lightPlacement;
};

double Light::getIntensity(){
    return lightIntensity;
};

double Light::getLightType(){
    return lightType;
};

class MaterialColor{
    public:
        MaterialColor();
        MaterialColor(Vector3 newOD, Vector3 newOS, Vector3 newK, int colorN);
        Vector3 getOd();
        Vector3 getOs();
        void setOd(Vector3 newOD);
        Vector3 getK();
        int getN();
    private:
        Vector3 Od;
        Vector3 Os;
        Vector3 K;
        int n;
};

MaterialColor::MaterialColor(){};

MaterialColor::MaterialColor(Vector3 newOD, Vector3 newOS, Vector3 newK, int colorN){
    Od = newOD;
    Os = newOS;
    K = newK;
    n = colorN;
};

Vector3 MaterialColor::getOd(){
    return Od;
};

Vector3 MaterialColor::getOs(){
    return Os;
};

Vector3 MaterialColor::getK(){
    return K;
};

int MaterialColor::getN(){
    return n;
};

void MaterialColor::setOd(Vector3 newOD){Od = newOD;};


class Image{
    public:
        Image(string imageName, int width, int height);
        int getwidth();
        int getheight();
        void setPixels();
        Vector3 getPixelColor(int row, int col);
        string getFile();
    private:
        string fileName;
        int width;
        int height;
        vector<Vector3> pixels;
};

Image::Image(string name, int w, int h){
    fileName = name;
    height = h;
    width = w;
};

int Image::getwidth(){return width;};
int Image::getheight(){return height;};
string Image::getFile(){return fileName;};
void Image::setPixels(){
    ifstream inputFile(fileName);
    string line;

    int r;
    int g;
    int b;
    int rowCount = 0;
    int check = 0;
    if(inputFile.is_open()){
        getline(inputFile, line);
        while(getline(inputFile, line)){
            istringstream in(line);
            for(int i = 0; i < width; i++){
                in >> r;
                in >> g;
                in >> b;
                Vector3 color = Vector3(r,g,b);
                int curPixel = rowCount*height + i*width;  
                pixels.push_back(color);
                check++;
            }
            rowCount++;
        }
    } else {
        cout << "Image could not get file" << endl;
    }
    inputFile.close();
    cout << "TOTAL PIXELS: " << check << endl;

    //pixels.at(0).print_vec();
};

Vector3 Image::getPixelColor(int row, int col){
    int color = row*width + col;
    if(color >= pixels.size()){
        return pixels.at(color - 1);
    }
    return pixels.at(color);
};


Image genImage(string texture){
    ifstream inputFile(texture);
    string line;
    string type;
    int width;
    int height;
    if(inputFile.is_open()){
        getline(inputFile, line);
        istringstream in(line);
        in >> type;
        in >> width;
        in >> height;
    }
    else{
        return Image(texture, -1, -1);
    }
    inputFile.close();
    return Image(texture, width, height);
};

int count = 0;
vector<Image> textureFiles;
int colorCount = 0;



//SPHERE
class Sphere{
    public:
        Sphere(Vector3 cirPos, double cirR, MaterialColor color, bool texture, int textureFileNum);
        //Sphere(Vector3 cirPos, double cirR, MaterialColor color, bool texture);
        void setR(double newR);
        double getR();
        Vector3 getSpherePos();
        void setColor(MaterialColor newColor);
        MaterialColor getColor();
        void printSphere();
        bool hasTexture();
        int getTexture();
    private:
        double r;
        MaterialColor circle_color;
        Vector3 pos;
        bool texture;
        int textureFile;

};

// Sphere::Sphere(Vector3 cirPos, double cirR, MaterialColor color, bool cirTexture){
//     pos = cirPos;
//     r = cirR;
//     circle_color = color;
//     texture = cirTexture;
//     textureFile = -1;
// };

Sphere::Sphere(Vector3 cirPos, double cirR, MaterialColor color, bool cirTexture, int curtexture){
    pos = cirPos;
    r = cirR;
    circle_color = color;
    texture = cirTexture;
    textureFile = curtexture;
};

int Sphere::getTexture(){return textureFile;};

bool Sphere::hasTexture(){return texture;};

double Sphere::getR(){return r;};
void Sphere::setR(double newR){r = newR;};

void Sphere::setColor(MaterialColor newColor){circle_color = newColor;};
MaterialColor Sphere::getColor(){return circle_color;};

void Sphere::printSphere(){
    cout << "Testing Sphere: " << endl;
    cout << "Pos: ";
    pos.print_vec();
    cout << "Radius: " << r << endl;
    // cout << "Color: ";
    // circle_color.print_vec();
};

Vector3 Sphere::getSpherePos(){
    return pos;
};

//More technical things we will need
vector<Sphere> circles;

bool debug = false;

float getDistance(Sphere circle, Vector3 origin, Vector3 ray, bool test){
    double cX = circle.getSpherePos().getX();
    double cY = circle.getSpherePos().getY();
    double cZ = circle.getSpherePos().getZ();

    double xd = ray.getX();
    double yd = ray.getY();
    double zd = ray.getZ();

    //cout << "Testing pixel ray: " << xd << " " << yd << " " << zd << endl; 

    double xO = origin.getX();
    double yO = origin.getY();
    double zO = origin.getZ();

    double radius = circle.getR();

    double B = 2 * (xd*(xO - cX) + yd*(yO - cY) + zd*(zO - cZ));
    double C = ((xO - cX) * (xO - cX)) + ((yO - cY) * (yO - cY)) + ((zO - cZ) * (zO - cZ)) - (radius * radius);
    double discriminant = ((B*B) - 4*C);
    if(test){
        // cout << "B: " << B << endl;
        // cout << "C: " << C << endl;
        // cout << "Discriminant: " << discriminant << endl; 
    }
    
    if (discriminant < 0){return -1;}
    else{

        //cout << "TEST " << k << " PASSED" << endl;
        float d1 = ((-1*B) + sqrt(discriminant))/2;
        float d2 = ((-1*B) - sqrt(discriminant))/2;

        if((d1 >= 0) && (d2 < 0)){return d1;}
        if((d2 >= 0) && (d1 < 0)){return d2;}

        //if(test){cout << "D1: " << d1 << " D2: " << d2 << endl;}

        //if you are in the circle, this needs to be edited
        if((d1 >= 0) && (d2 >=0)){
            if((d1 <= d2)){return d1;}
            else{return d2;}   
        }
    }
    return -1;
};


class Ray{
    public:
        Ray(Vector3 origin, Vector3 direction);
        Vector3 getOrigin();
        Vector3 getDir();
        Vector3 totalRay();
    private:
        Vector3 origin;
        Vector3 direction;
        Vector3 rayPoint;
};

Ray::Ray(Vector3 newOrigin, Vector3 newDirection){
    origin = newOrigin;
    direction = newDirection;
    rayPoint = origin.add(direction);
};

Vector3 Ray::getOrigin(){return origin;};
Vector3 Ray::getDir(){return direction;};
Vector3 Ray::totalRay(){return rayPoint;};



class Triangle{
    public:
        Triangle(Vector3 vertices, Vector3 normals, Vector3 uv, int type, int texture, MaterialColor color, bool hasTexture);
        Vector3 getVerts();
        Vector3 getNorms();
        Vector3 getUV();
        int getTexture();
        bool hasTexture();
        int getType();
        MaterialColor getColor();
        void setColor(MaterialColor newColor);
    private:
        Vector3 vertices;
        Vector3 normals;
        Vector3 uvCoords; 
        int type;
        int texture;
        bool textureFlag;
        MaterialColor color;

};

Triangle::Triangle(Vector3 verts, Vector3 n, Vector3 uv, int triType, int newtexture, MaterialColor newcolor, bool hasTexture){
    vertices = verts;
    normals = n;
    uvCoords = uv;
    type = triType;
    texture = newtexture;
    color = newcolor;
    textureFlag = hasTexture;
};

Vector3 Triangle::getVerts(){return vertices;};
Vector3 Triangle::getNorms(){return normals;};
Vector3 Triangle::getUV(){return uvCoords;};

int Triangle::getType(){return type;}
int Triangle::getTexture(){return texture;}
bool Triangle::hasTexture(){return textureFlag;}
MaterialColor Triangle::getColor(){return color;}
void Triangle::setColor(MaterialColor newColor){color = newColor;}

vector<Vector3> vertex;
vector<Vector3> vertexNormals;
vector<Vector3> uvCoords;
vector<Triangle> triangles;
vector<Image> textures;
bool polyTester = false;

//RAYTRACER 1C TRIANGLE CALCULATIONS
double hitPlane(Ray curRay, Vector3 p0, Vector3 p1, Vector3 p2){
    Vector3 origin = curRay.getOrigin();
    Vector3 dir = curRay.getDir();
    
    Vector3 e1 = p1.subtract(p0);
    Vector3 e2 = p2.subtract(p0);
    Vector3 n = e1.cross(e2);

    // e1.print_vec();
    // e2.print_vec();

    
    //n.normalize();

    double A = n.getX();
    double B = n.getY();
    double C = n.getZ();

    double xO = origin.getX();
    double yO = origin.getY();
    double zO = origin.getZ();

    double xd = dir.getX();
    double yd = dir.getY();
    double zd = dir.getZ();

    double D  = -1 *(A*p0.getX() + B*p0.getY() + C*p0.getZ());

    double distance = -1*(A*xO + B*yO + C*zO + D)/(A*xd + B*yd + C*zd);
    //double checker = (A*xd + B*yd + C*zd);
    //cout << distance << endl;
    // if(polyTester) {
    //     origin.print_vec();
    //     n.print_vec();
    //     dir.print_vec();
    //     cout << "D: " << D << endl;
    //     cout << distance << endl;
    // }

    if(distance < 0){return -1;}

    return distance;

};

Vector3 TriangleHit(Triangle curTri, Ray curRay, double t){
    Vector3 verts = curTri.getVerts();
    
    Vector3 p0 = vertex.at(verts.getX());
    Vector3 p1 = vertex.at(verts.getY());
    Vector3 p2 = vertex.at(verts.getZ());
    if(polyTester){
        p0.print_vec();
        p1.print_vec();
        p2.print_vec();
    }

    Vector3 origin = curRay.getOrigin();
    Vector3 dir = curRay.getDir();
    
    Vector3 p = dir.mul(t);
    p.plus(origin);
    

    Vector3 ep = p.subtract(p0);
    Vector3 e1 = p1.subtract(p0);
    Vector3 e2 = p2.subtract(p0);


    if(polyTester){
        dir.print_vec();
        cout << t << endl;
        cout << "Ray Point:" << endl;
        p.print_vec();
        cout << "E Vectors: " << endl;
        ep.print_vec();
        e1.print_vec();
        e2.print_vec();

    }

    double d11 = e1.dot(e1);
    double d22 = e2.dot(e2);
    double d12 = e1.dot(e2);
    double d1p = e1.dot(ep);
    double d2p = e2.dot(ep);

    double det = d11*d22 - d12*d12;

    double B = (d22*d1p - d12*d2p)/det;
    double y = (d11*d2p - d12*d1p)/det;

    if(polyTester){

        cout << "D11:" << d11 << " D22: " << d22 << " D12: " << d12 << endl;
        cout << "D1p:" << d1p << " D2p: " << d2p << endl;

        cout << "DET: " << det << endl;

        cout << "Bare Coords:" << endl;
        cout << B << " " << y << endl;

    }

    if((B < 0) || (B > 1) || (y < 0) || (y > 1) || ((B + y) > 1)){
        return Vector3(-1,-1,1);
    }
    
    return Vector3((1 - (B+y)), B, y);
};

Vector3 planeNormal(Vector3 p0, Vector3 p1, Vector3 p2){
    Vector3 e1 = p1.subtract(p0);
    Vector3 e2 = p2.subtract(p0);
    Vector3 n = e1.cross(e2);
    n.normalize();
    return n;
};

//RAYTRACERS 1B LIGHT CALCULATIONS
float ShadeRay(Light currentLight, Vector3 rayIntersectionPoint, int hitIndex, bool polygon){
    Vector3 LightPos = currentLight.getLightPlace();
    Vector3 LightRay = LightPos.subtract(rayIntersectionPoint);
    LightRay.normalize();
    if(currentLight.getLightType() == 0){
        for(int i = 0; i < circles.size(); i++){
            if((i == hitIndex) && (!polygon)){continue;}
            float check = getDistance(circles.at(i), rayIntersectionPoint, LightRay, false);
            if(check >= 0){
                cout << check << endl;
                return 0;
            }
        }
        //Vector3 adjustedIntersection = Vector3();
        // for (int i = 0; i < triangles.size(); i++){
        //     if((i == hitIndex) && (polygon)){continue;}
        //     int v0 = triangles.at(i).getVerts().getX();
        //     int v1 = triangles.at(i).getVerts().getY();
        //     int v2 = triangles.at(i).getVerts().getZ();
        //     Vector3 planeNormal = (vertex.at(v0), vertex.at(v1), vertex.at(v2));
        //     //Vector3 adjustedIntersection = planeNormal.add(rayIntersectionPoint);
        //     Ray posToLight = Ray(rayIntersectionPoint, LightRay);
        //     double planeDist = hitPlane(posToLight, vertex.at(v0), vertex.at(v1), vertex.at(v2));
        //     if(planeDist >= 0){
        //         Vector3 hitTri = TriangleHit(triangles.at(i), posToLight, planeDist);
        //         if(hitTri.getX() == -1){continue;}
        //         cout << "TRIANGLE MAKES SHADOW: " << i << endl;
        //         return 0;
        //     }
        // }

        return 1;   
    }
    else if(currentLight.getLightType() == 1 || currentLight.getLightType() == 2){
        float rayLength = LightPos.distance(rayIntersectionPoint);
        for(int i = 0; i < circles.size(); i++){
            if(i == hitIndex){continue;}
            float check = getDistance(circles.at(i), rayIntersectionPoint, LightRay, false);
            if((check >= 0) && (check < rayLength)){return 0;}
        }
        Vector3 adjustedIntersection = Vector3();
        // for (int i = 0; i < triangles.size(); i++){
         
        //     int v0 = triangles.at(i).getVerts().getX();
        //     int v1 = triangles.at(i).getVerts().getY();
        //     int v2 = triangles.at(i).getVerts().getZ();
        //     Vector3 planeNormal = (vertex.at(v0), vertex.at(v1), vertex.at(v2));
        //     Vector3 adjustedIntersection = planeNormal.add(rayIntersectionPoint);
        //     Ray posToLight = Ray(adjustedIntersection, LightRay);
        //     double planeDist = hitPlane(posToLight, vertex.at(v0), vertex.at(v1), vertex.at(v2));
        //     if((planeDist >= 0) && (planeDist < rayLength)){
        //         Vector3 hitTri = TriangleHit(triangles.at(i), posToLight, planeDist);
        //         if(hitTri.getX() == -1){continue;}
        //         //cout << "TRIANGLE MAKES SHADOW: " << i << endl;
        //         return 0;
        //     }
        // }
        return 1;
    }
    return 0;
}


Vector3 polyColor(Ray currRay, vector<Light>AllLights, Triangle curTri, double planeDist, int hitIndex){
    Vector3 currRayPoint = currRay.getOrigin();
    Vector3 rayDirection = currRay.getDir();
    rayDirection.normalize();

    rayDirection.times(planeDist);
    Vector3 rayIntersectionPoint = currRayPoint.add(rayDirection);

    Vector3 v0 = vertex.at(curTri.getVerts().getX());
    Vector3 v1 = vertex.at(curTri.getVerts().getY());
    Vector3 v2 = vertex.at(curTri.getVerts().getZ());

    MaterialColor colorValues = curTri.getColor();
    if(polyTester){
        cout << "TRIANGLE TYPE: " << curTri.getType() << endl;
    }

    Vector3 normal = Vector3();
    if(curTri.getType() == 1){
        Vector3 e1 = v1.subtract(v0);
        Vector3 e2 = v2.subtract(v0);
        normal = e1.cross(e2);
    }
    else if((curTri.getType() == 2)  || (curTri.getType() == 4)){
        Vector3 ABY = TriangleHit(curTri, currRay, planeDist);
        Vector3 n0 = vertexNormals.at(curTri.getNorms().getX());
        Vector3 n1 = vertexNormals.at(curTri.getNorms().getY());
        Vector3 n2 = vertexNormals.at(curTri.getNorms().getZ());
        n0.times(ABY.getX());
        n1.times(ABY.getY());
        n2.times(ABY.getZ());
        n0.plus(n1);
        n0.plus(n2);
        normal = n0;
        if(curTri.getType() == 4){
            Vector3 uv0 = uvCoords.at(curTri.getUV().getX());
            Vector3 uv1 = uvCoords.at(curTri.getUV().getY());
            Vector3 uv2 = uvCoords.at(curTri.getUV().getZ());
            uv0.times(ABY.getX());
            uv1.times(ABY.getY());
            uv2.times(ABY.getZ());
            if(polyTester){
                uv0.print_vec();
                uv1.print_vec();
                uv2.print_vec();
                polyTester = false;
            }
            double u = uv0.getX() + uv1.getX() + uv2.getX();
            double v = uv0.getY() + uv1.getY() + uv2.getY();
            int triTexture = curTri.getTexture();
            int height = textureFiles.at(triTexture).getheight();
            int width = textureFiles.at(triTexture).getwidth();
            int row = height * v;
            int col = width * u;
            Vector3 newColor = textureFiles.at(triTexture).getPixelColor(row, col);

            newColor.setX(newColor.getX() / 255);
            newColor.setY(newColor.getY() / 255);
            newColor.setZ(newColor.getZ() / 255);
            colorValues.setOd(newColor);
        }
    }
    else if(curTri.getType() == 3){
        Vector3 e1 = v1.subtract(v0);
        Vector3 e2 = v2.subtract(v0);
        normal = e1.cross(e2);
        
        Vector3 ABY = TriangleHit(curTri, currRay, planeDist);
        Vector3 uv0 = uvCoords.at(curTri.getUV().getX());
        Vector3 uv1 = uvCoords.at(curTri.getUV().getY());
        Vector3 uv2 = uvCoords.at(curTri.getUV().getZ());
        // uv0.print_vec();
        // uv1.print_vec();
        // uv2.print_vec();
        uv0.times(ABY.getX());
        uv1.times(ABY.getY());
        uv2.times(ABY.getZ());
        
        double u = uv0.getX() + uv1.getX() + uv2.getX();
        while(u > 1){
            u =  u - 1;
        }
        double v = uv0.getY() + uv1.getY() + uv2.getY();
        while(v > 1){
            v = v - 1;
        }
        //cout << u << " " << v << endl;
        int triTexture = curTri.getTexture();
        
        int height = textureFiles.at(triTexture).getheight();
        int width = textureFiles.at(triTexture).getwidth();
        int row = height * v;
        int col = width * u;
        //cout << triTexture << endl;
        Vector3 newColor = textureFiles.at(triTexture).getPixelColor(row, col);

        newColor.setX(newColor.getX() / 255);
        newColor.setY(newColor.getY() / 255);
        newColor.setZ(newColor.getZ() / 255);
        colorValues.setOd(newColor);
        //cout << "CHECKPOINT 1 PASSED" << endl;
    }


    normal.normalize();

    Vector3 Kvalues = colorValues.getK();
    Vector3 ambient = colorValues.getOd();
    ambient.times(Kvalues.getX());
    Vector3 sum = Vector3(0,0,0);

    for(int i = 0; i < AllLights.size(); i++){
        
        // float SFlag = ShadeRay(AllLights.at(i), rayIntersectionPoint, hitIndex, true);
        // if(SFlag == 0){continue;}
        
        //get our current K values
        Vector3 diffuse = colorValues.getOd();
        diffuse.times(Kvalues.getY());
        //diffuse.print_vec();

        //obtain our light
        Vector3 L;
        Light curLight = AllLights.at(i);
        L = curLight.getLightPlace();
        //directional light
        if(curLight.getLightType() == 0){
            L.times(-1);
            //cout << "test" << endl;
            if(debug){L.print_vec();}
        }
        //point light
        else if(curLight.getLightType() == 1 || curLight.getLightType() == 2){
            L.minus(rayIntersectionPoint);
        }
        
        L.normalize();

        double nLDot = normal.dot(L);
        if(nLDot < 0){nLDot = 0;}
        //finish our defuse and clamp to 1

        

        diffuse.times(nLDot);
        diffuse.clamp(0.0,1.0);

        Vector3 specular = colorValues.getOs();
        specular.times(Kvalues.getZ());
        //specular.print_vec();
        

        //get our V
        Vector3 V = currRay.getOrigin();
        V.minus(rayIntersectionPoint);
        
        V.normalize();

        //H = (L + V)/||(L + V)||
        Vector3 H = L.add(V);
        H.times(0.5);

        H.normalize();
        double nHDot = normal.dot(H);
    
        //check for negative angles
        if(nHDot < 0){nHDot = 0;}
        
        //make sure to apply the exponent
        int n = colorValues.getN();
        double totalNH = pow(nHDot, n);
        specular.times(totalNH);
         //clamp to one
        specular.clamp(0.0,1.0);

        Vector3 minorSum = Vector3(0,0,0);
        minorSum.plus(diffuse);
        minorSum.plus(specular);
        minorSum.times(curLight.getIntensity());

        sum.plus(minorSum);
    }

    sum.plus(ambient);
        //sum.print_vec();

        //clamp to one
    if(sum.getX() > 1){
        sum.setX(1);
    }
    if(sum.getY() > 1){
        sum.setY(1);
    }
    if(sum.getZ() > 1){
        sum.setZ(1);
    }



    return sum;




};

Vector3 colorPixel(Ray currRay, vector<Light>AllLights, Sphere curCircle, double rayDist, int hitIndex){
    
    //get our Ray intersection point
    Vector3 currRayPoint = currRay.getOrigin();
    Vector3 rayDirection = currRay.getDir();
    rayDirection.normalize();

    if(debug){
        cout << "ray dist: " << rayDist << endl; 
        currRayPoint.print_vec();
        rayDirection.print_vec();
    }

    rayDirection.times(rayDist);
    
    Vector3 rayIntersectionPoint = currRayPoint.add(rayDirection);

    //Vector3 test = curCircle.getColor().getOd();
    //test.print_vec();
    //Vector3 rayIntersectionPoint = rayDirection;

    if(debug){
        cout << "Ray Intersection Point: ";
        rayIntersectionPoint.print_vec();
    }

    //cout << "Distance to Sphere: " << rayIntersectionPoint.distance(curCircle.getSpherePos()) << endl;

   
    //get our normal
    Vector3 normal = rayIntersectionPoint.subtract(curCircle.getSpherePos());
    normal.normalize();

    //double circleRadius = 1 / curCircle.getR();
    //normal.times(circleRadius);
    // cout << "Normal: ";
    // normal.print_vec();

    //get our color values and set up sums for diffuse and specular
    MaterialColor colorValues = curCircle.getColor();
    Vector3 Kvalues = colorValues.getK();

    Vector3 ambient = colorValues.getOd();
    
    ambient.times(Kvalues.getX());

    Vector3 sum = Vector3(0,0,0);


    for(int i = 0; i < AllLights.size(); i++){

        // float SFlag = ShadeRay(AllLights.at(i), rayIntersectionPoint, hitIndex, false);
        // if(SFlag == 0){continue;}

        //get our current K values
        Vector3 diffuse = colorValues.getOd();
        diffuse.times(Kvalues.getY());
        //diffuse.print_vec();

        //obtain our light
        Vector3 L;
        Light curLight = AllLights.at(i);
        L = curLight.getLightPlace();

        
        //check to see what type of light we have
        //directional light = 0, point light = 1

        //directional light
        if(curLight.getLightType() == 0){
            L.times(-1);
            //cout << "test" << endl;
            if(debug){L.print_vec();}
        }
        //point light
        else if(curLight.getLightType() == 1 || curLight.getLightType() == 2){
            L.minus(rayIntersectionPoint);
        }
        
        L.normalize();

        //get our first dot product
        double nLDot = normal.dot(L);
        if(nLDot < 0){nLDot = 0;}
        //finish our defuse and clamp to 1

        

        diffuse.times(nLDot);
        diffuse.clamp(0.0,1.0);

        Vector3 specular = colorValues.getOs();
        specular.times(Kvalues.getZ());
        //specular.print_vec();
        

        //get our V
        Vector3 V = currRay.getOrigin();
        V.minus(rayIntersectionPoint);
        
        // if(debug){
        //     cout << "RSP: ";
        //     rayIntersectionPoint.print_vec();
        //     cout << "V: ";
        //     V.print_vec();
        // }

        V.normalize();

        //H = (L + V)/||(L + V)||
        Vector3 H = L.add(V);
        H.times(0.5);

        if(debug){
            cout << "H: ";
            H.print_vec();
        }

        H.normalize();
        double nHDot = normal.dot(H);
    
        //check for negative angles
        if(nHDot < 0){nHDot = 0;}
        
        //make sure to apply the exponent
        int n = colorValues.getN();
        double totalNH = pow(nHDot, n);
        specular.times(totalNH);
         //clamp to one
        specular.clamp(0.0,1.0);

    

        if(debug){
            cout << "Diffuse: ";
            diffuse.print_vec();
            cout << "nLDot: " << nLDot << endl;
            cout << endl;

            cout << "Specular: ";
            specular.print_vec();
            cout << "nHDot: " << nHDot << endl;
            cout << "totalNH: " << totalNH << endl;
        }




        Vector3 minorSum = Vector3(0,0,0);
        minorSum.plus(diffuse);
        minorSum.plus(specular);
        minorSum.times(curLight.getIntensity());

        if(curLight.getLightType() == 2){
            Vector3 LightPos = curLight.getLightPlace();
            Vector3 cValues = curLight.getAttLight();
            double d = LightPos.distance(rayIntersectionPoint);
            double attLight = 1 /(cValues.getX() + (d* cValues.getY()) + (d*d * cValues.getZ()));
            minorSum.times(attLight);
        }

        sum.plus(minorSum);

        //printf("Diffuse: %f %f %f\n", diffuse.getX(), diffuse.getY(), diffuse.getZ());
        //printf("Specular: %f %f %f\n", specular.getX(), specular.getY(), specular.getZ());
    }

    sum.plus(ambient);
    //sum.print_vec();

    //clamp to one
    if(sum.getX() > 1){
        sum.setX(1);
    }
    if(sum.getY() > 1){
        sum.setY(1);
    }
    if(sum.getZ() > 1){
        sum.setZ(1);
    }



    return sum;

}


Vector3 textureCircleColor(Ray currRay, Sphere curCircle, double rayDist){
    //get our Ray intersection point
    Vector3 currRayPoint = currRay.getOrigin();
    Vector3 rayDirection = currRay.getDir();
    rayDirection.normalize();
    rayDirection.times(rayDist);
    Vector3 rayIntersectionPoint = currRayPoint.add(rayDirection);
    Vector3 normal = rayIntersectionPoint.subtract(curCircle.getSpherePos());
    normal.normalize();

    double theta = atan2(normal.getY(), normal.getX());
    double omega = acos(normal.getZ());
    double v = omega/M_PI;
    double u = 0;

    if(theta > 0){
        u = theta / (2 * M_PI);
    }
    else if (theta < 0){
        u = (theta + 2*M_PI)/(2 * M_PI);
    }
    
    // cout << "Omega: " << omega << endl;
    // cout << "Theta: " << theta << endl;
    // cout << "V: " << v << endl;
    // cout << "U: " << u << endl;

    //Vector3 textureColor = Vector3();
    int circleTexture = curCircle.getTexture();
    int height = textureFiles.at(circleTexture).getheight();
    int width = textureFiles.at(circleTexture).getwidth();

    int row = height * v;
    int col = width * u;
    Vector3 newColor = textureFiles.at(circleTexture).getPixelColor(row, col);

    newColor.setX(newColor.getX() / 255);
    newColor.setY(newColor.getY() / 255);
    newColor.setZ(newColor.getZ() / 255);
    return newColor;
    
    // double r;
    // double g;
    // double b;
    // string type;
    // int row;
    // int col;
    //int lineCounter = 0;

    // ifstream inputFile(input);
    // string line;
    // if(inputFile.is_open()){
    //     while(getline(inputFile, line)){
    //        if(lineCounter == 0){
    //             istringstream in(line);
    //             in >> type;
    //             in >> width;
    //             in >> height;
    //             row = (int) (height * v);
    //             col = (int)(width * u);
    //        }
    //        if(lineCounter == (row)){
    //             istringstream in(line);
    //             for(int j = 0; j < col; j++){
    //                 in >> r;
    //                 in >> g;
    //                 in >> b;
    //                 //cout << r <<  " " << g << " " << b << endl;
    //             }
    //        }
    //        lineCounter++;
    //        //cout << "Line Counter: " << lineCounter << endl;
    //     }
    //     textureColor = Vector3(r/255,g/255,b/255);
    // }
    // inputFile.close();
    
    //return textureColor;
}



int main(int argc, char* argv[]){
    if(argc < 2){
        cout << "Nothing inputed, closing program" << endl;
        return 0;
    }
    string input = argv[1];

    //auto start = std::chrono::system_clock::now();

    //all Vectors we are going to need
    Vector3 eye;
    Vector3 viewDir;
    Vector3 up;
    Vector3 n;

    //Colors
    Vector3 bkgcolor;
    MaterialColor mtlcolor;

    Vector3 u;
    Vector3 v;


    //More technical things we will need
    //vector<Sphere> circles;

    //extra variables for collecting data for our vectors
    double x;
    double y;
    double z;
    double r;
    double lightType;

    //other pieces of data we will need
    double hfov;
    double imageHeight;
    double imageWidth;

    //lights
    vector<Light> pointLights;


    //vertexs for triangles
    bool flatShade;


    // cout << "Welcome to Ray Tracer v.01: Please Enter your file: ";
    // cin >> input;
    
    ifstream inputFile(input);
    string line;
    string curTexture = "";
    bool textureFlag = false;
    int numTextures = -1;

    //read in our lines from the file
    if(inputFile.is_open()){
        while(getline(inputFile, line)){
            istringstream in(line);
            string type;
            string ppmFinder = "";
            in >> type;

            if(type == "texture"){
                in >> curTexture;
                textureFlag = true;
                Image curImage = genImage(curTexture);
                curImage.setPixels();
                textureFiles.push_back(curImage);
                numTextures++;
                cout << "CURRENT TEXTURE: " << curTexture << endl;
                //cout << "texture found" << endl;
            }

            //view origin
            if(type == "eye"){
                in >> x;
                in >> y;
                in >> z;
                eye.setX(x);
                eye.setY(y);
                eye.setZ(z);
            }
            
            //view direction
            else if(type == "viewdir"){
                //cout << "viewdir PASSED" << endl;
                in >> x;
                in >> y;
                in >> z;
                viewDir.setX(x);
                viewDir.setY(y);
                viewDir.setZ(z);
            }

            //up vector
            else if (type == "updir"){
                //cout << "up PASSED" << endl;
                in >> x;
                in >> y;
                in >> z;
                up.setX(x);
                up.setY(y);
                up.setZ(z);
            }

            else if(type == "hfov"){
                //cout << "hfov PASSED" << endl;
                in >> hfov;
            }
            
            //image size
            else if(type == "imsize"){
                //cout << "imsize PASSED" << endl;
                in >> imageWidth;
                in >> imageHeight;
            }

            //get our background color
            else if(type == "bkgcolor"){
                //cout << "bkgcolor PASSED" << endl;
                in >> x;
                in >> y;
                in >> z;
                bkgcolor.setX(x);
                bkgcolor.setY(y);
                bkgcolor.setZ(z);
            }

            //get our sphere color
            else if(type == "mtlcolor"){
                //cout << "mtlcolor PASSED" << endl;
                double odr;
                double odg;
                double odb;
                double osr;
                double osg;
                double osb;
                double ka;
                double kd;
                double ks;
                int n;
                in >> odr;
                in >> odg;
                in >> odb;
                Vector3 Od = Vector3(odr,odg,odb);
                in >> osr;
                in >> osg;
                in >> osb;
                Vector3 Os = Vector3(osr,osg,osb);
                in >> ka;
                in >> kd;
                in >> ks;
                Vector3 K = Vector3(ka,kd,ks);
                in >> n;
                mtlcolor = MaterialColor(Od,Os,K,n);
                textureFlag = false;
                curTexture = "";
            }
            

            else if(type == "light"){
                double lightType;
                double lightIntensity;
                in >> x;
                in >> y;
                in >> z;
                in >> lightType;
                in >> lightIntensity;
                Vector3 lightPos = Vector3(x,y,z);
                Light curLight = Light(lightPos, lightIntensity, lightType);
                pointLights.push_back(curLight);
            }

            else if(type == "attlight"){
                double lightType;
                double lightIntensity;
                double c1;
                double c2;
                double c3;
                in >> x;
                in >> y;
                in >> z;
                in >> lightType;
                in >> lightIntensity;
                in >> c1;
                in >> c2;
                in >> c3;
                Vector3 lightPos = Vector3(x,y,z);
                Light curLight = Light(lightPos, lightIntensity, lightType);
                Vector3 attLight = Vector3(c1,c2,c3);
                curLight.setAttLight(attLight);
                pointLights.push_back(curLight);
                //cout << pointLights.size();
            }


            //get our spheres
            else if(type == "sphere"){
                in >> x;
                in >> y;
                in >> z;
                in >> r;
                Vector3 cirPos = Vector3(x,y,z);
                //Sphere curSphere;
                //cout << texture << endl;
                Sphere curSphere = Sphere(cirPos, r, mtlcolor, textureFlag, numTextures);
               
                circles.push_back(curSphere);

                //cout << "sphere PASSED" << endl;
                //cout << "sphere Count: " << circles.size() << endl;
            }

            else if(type == "v"){
                in >> x;
                in >> y;
                in >> z;
                Vector3 curVertex = Vector3(x,y,z);
                vertex.push_back(curVertex);
                //cout << "VERT MADE: ";
                //curVertex.print_vec();
            }

            else if(type == "vn"){
                in >> x;
                in >> y;
                in >> z;
                Vector3 curNormal = Vector3(x,y,z);
                vertexNormals.push_back(curNormal);
            }

            else if(type == "vt"){
                in >> x;
                in >> y;
                Vector3 uv = Vector3(x,y, -1);
                uvCoords.push_back(uv);
            }



            else if(type == "f"){
                //cout << "ON F" << endl;
                //triangle type1 = vertex
                //type2 = vertex and normals
                //type3 = vertex and texture coords
                //type4 = vertex, normal and texture coords
                Vector3 triVerts;
                Vector3 triNorms;
                Vector3 triUV;
                int v1;
                int v2;
                int v3;
                int vn1;
                int vn2;
                int vn3;
                int vt1;
                int vt2;
                int vt3;
                int tester;
                int lineSize = 128;
                char cmd[lineSize];
                
                for(int i = 1; i < line.length(); i++){
                    cmd[i - 1] = line.at(i);
                }
                //int check = sscanf(line, "%d %d %d", &v1, &v2, &v3);
                if (sscanf(cmd, "%d/%d/%d %d/%d/%d %d/%d/%d", &v1,&vt1,&vn1,&v2,&vt2,&vn2,&v3,&vt3,&vn3) == 9){
                    triVerts = Vector3(v1 - 1,v2 - 1,v3 - 1);
                    triNorms = Vector3(vn1 - 1,vn2 - 1,vn3 - 1);
                    triUV = Vector3(vt1 - 1,vt2 - 1,vt3 - 1);
                    Triangle curTriangle(triVerts, triNorms, triUV, 4, numTextures,mtlcolor,textureFlag);
                    triangles.push_back(curTriangle);
                }
                else if(sscanf(cmd, "%d//%d %d//%d %d//%d", &v1,&vn1,&v2,&vn2,&v3,&vn3) == 6){
                    triVerts = Vector3(v1 - 1,v2 - 1,v3 - 1);
                    triNorms = Vector3(vn1 - 1, vn2 - 1, vn3 - 1);
                    triUV = Vector3();
                    Triangle curTriangle = Triangle(triVerts, triNorms, triUV, 2, numTextures, mtlcolor, textureFlag);
                    triangles.push_back(curTriangle);
                    cout << "TRIANGLE Type 2 MADE " << endl;
                    triVerts.print_vec();
                }
                else if(sscanf(cmd, "%d/%d %d/%d %d/%d", &v1,&vt1,&v2,&vt2,&v3,&vt3) == 6){
                    triVerts = Vector3(v1 - 1,v2 - 1,v3 - 1);
                    triNorms = Vector3();
                    triUV = Vector3(vt1 - 1,vt2 - 1,vt3 - 1);
                    Triangle curTriangle = Triangle(triVerts, triNorms, triUV, 3, numTextures, mtlcolor, textureFlag);
                    triangles.push_back(curTriangle);
                    //cout << "TRIANGLE Type 3 MADE " << endl;
                    //triUV.print_vec();
                    //cout << numTextures << endl;
                }   
                else if(sscanf(cmd, "%d %d %d", &v1, &v2, &v3) == 3){
                    triVerts = Vector3(v1 - 1,v2 - 1,v3 - 1);
                    triNorms = Vector3();
                    triUV = Vector3();
                    Triangle curTriangle = Triangle(triVerts, triNorms, triUV, 1, numTextures, mtlcolor, textureFlag);
                    triangles.push_back(curTriangle);
                    cout << "TRIANGLE Type 1 MADE " << endl;
                    triVerts.print_vec();
                }
            }
        }
        inputFile.close();

    }
    else{
        cout << "Not a valid file, closing program" << endl;
        return 0;
    }

    cout << "TESTING IMSIZE: ";
    cout << imageHeight << " " << imageWidth << endl;
    
    //obtain u and v
    viewDir.normalize();
    u = viewDir.cross(up);
    u.normalize();

    v = u.cross(viewDir);
    v.normalize();

    //obtain view width and height
    double d = 1;
    double aspect_ratio = imageWidth / imageHeight;
    double view_W = 2 * d *  tan(0.5* (hfov * M_PI) /180 );
    double view_H = view_W/aspect_ratio;

    //cout << "TESTING VIEW DIMENSIONS: W:" << view_W << " H: " << view_H << endl;

    //obtain corners
    n = viewDir;
    n.times(d);

    view_H *= 0.5;
    view_W *= 0.5;
    u.times(view_W);
    v.times(view_H);

    Vector3 viewOrigin = eye.add(n);

    Vector3 ul = viewOrigin;
    ul.minus(u);
    ul.plus(v);

    Vector3 ur = viewOrigin;
    ur.plus(u);
    ur.plus(v);

    Vector3 ll = viewOrigin;
    ll.minus(u);
    ll.minus(v);

    Vector3 lr = viewOrigin;
    lr.plus(u);
    lr.minus(v);


    //obtain deltas
    float deltaHDenominator = 1.0/(imageWidth - 1);
    float deltaVDenominator = 1.0/(imageHeight - 1);

    Vector3 deltaH = ur.subtract(ul);
    deltaH.times(deltaHDenominator);


    Vector3 deltaV = ll.subtract(ul);
    deltaV.times(deltaVDenominator);
    //cout << "CHECKPOINT" << endl;

    //vector<Vector3> pixels;
    int imgW = imageWidth;
    int imgH = imageHeight;
    //cout << "CHECKPOINT" << endl;
    //Vector3 pixels[imgH];
    Vector3 **pixels;
    pixels = new Vector3*[imgH];
    for(int i = 0; i < imgH; i++){
        pixels[i] = new Vector3[imgW];
    }

    int numpixels = 0;
    int checker = 0;
    cout << "CHECKPOINT 1" << endl;
    
    for(int i = 0; i < imageWidth; i++){
        for(int j = 0; j < imageHeight; j++){
            double minDistance = numeric_limits<double>::infinity();
            int hitIndex = -1;
            bool test = false;
            bool polygon = false;
            
            //get current pixel for direction of ray
            Vector3 currentPixel = ul;
            currentPixel.plus(deltaH.mul(i));
            currentPixel.plus(deltaV.mul(j));

    
            Vector3 ray = currentPixel.subtract(eye);
            ray.normalize();


            //create ray, then normalize
            Ray currentRay = Ray(eye,ray);

            //debug testing
            if((i == 450) && (j == 300)){
                polyTester = true;
                //ray.print_vec();
            }

            //iterate through circles, if we get a hit, check if its distance is lest than mindistance
            for(int k = 0; k < circles.size(); k++){
                double curDist = getDistance(circles.at(k), eye, ray, test);
                if((curDist >= 0) && (curDist < minDistance)){
                    hitIndex = k;
                    minDistance = curDist;
                }
            }
            for(int k = 0; k < triangles.size(); k++){
                int v0 = triangles.at(k).getVerts().getX();
                int v1 = triangles.at(k).getVerts().getY();
                int v2 = triangles.at(k).getVerts().getZ();
                double planeDist = hitPlane(currentRay, vertex.at(v0), vertex.at(v1), vertex.at(v2));
                if(polyTester){
                    cout << "Plane: " << planeDist << endl;
                    cout << "Triangle: " << k << endl;
                    cout << "Vertices: " << v0 << " " << v1 << " " << v2 << endl;
                }
                if((planeDist >= 0) && (planeDist < minDistance)){
                    Vector3 triCheck = TriangleHit(triangles.at(k), currentRay, planeDist);
                    if(polyTester){
                        cout << "Hit: " << triCheck.getX() << endl;
                        polyTester = false;
                    }
                    if(triCheck.getX() != -1){
                        minDistance = planeDist;
                        hitIndex = k;
                        polygon = true;
                    }
                }
                polyTester = false;
            }

            //if we did hit something, get the circles color, put it at that pixel index
            if(hitIndex >= 0){
                Vector3 pixelColor;
                // if(test){
                //     cout << minDistance << endl;
                //     Vector3 RSP = currentPixel.mul(minDistance);
                //     RSP.plus(eye);
                // }
                if(polygon){
                    pixelColor = polyColor(currentRay, pointLights, triangles.at(hitIndex), minDistance, hitIndex);
                }
                else{
                    if(circles.at(hitIndex).hasTexture() == true){
                        Vector3 newColor = textureCircleColor(currentRay, circles.at(hitIndex), minDistance);
                        //newColor.print_vec();
                        MaterialColor oldColor = circles.at(hitIndex).getColor();
                        oldColor.setOd(newColor);
                        circles.at(hitIndex).setColor(oldColor);
                    }
                    pixelColor = colorPixel(currentRay, pointLights, circles.at(hitIndex), minDistance, hitIndex);
                }
                pixels[j][i] = pixelColor;
            }
            else{
                //we missed all circles, get background color
                pixels[j][i] = bkgcolor;
            }
            debug = false;
            //cout << checker << endl;
            //checker++;
        }
    }

    input.erase(input.length() - 4, 4);
    string shortInput = "new";
    shortInput.append(input);
    shortInput.append(".ppm");
    cout << shortInput << endl;

    ofstream outputFile;

    outputFile.open(shortInput);
    outputFile << "P3\n";
    outputFile <<  imageWidth << "\n";
    outputFile << imageHeight << "\n";
    outputFile << "255\n";


    for(int i = 0; i < imgH; i++){
        for(int j = 0; j < imgW; j++){
            int r =(int) (pixels[i][j].getX() * 255);
            int g =(int) (pixels[i][j].getY() * 255);
            int b =(int) (pixels[i][j].getZ() * 255);
            outputFile << r << " " << g << " " << b << "\n";
        }
    }

    for(int i = 0; i < imgH; i++){
        delete[] pixels[i];
    }
    delete[] pixels;
    

    outputFile.close();
    return 0;
};

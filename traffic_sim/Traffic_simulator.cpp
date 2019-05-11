#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cmath>
#include <fstream>
#include <stdexcept>
#include <string>
#include "glad.h"
#include <GLFW/glfw3.h>

void Input(GLFWwindow *window)   //to exit when esc is pressed
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 color;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   color=aColor;\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 color;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(color, 1.0);\n"    //shape color
    "}\n\0";

using namespace std;
int main(int argc, char** argv)
{
    using namespace std::this_thread;
    using namespace std::chrono;
        
    int data[1][100];
    for(int p=0;p<100;p++)
    {
        data[0][p]=0;
    }
    
    int truck_width;
    int truck_length;
    int bus_length;
    int bus_width;
    int bike_length;
    int bike_width;
    int car_length;
    int car_width;
    int car_maxspeed;
    int car_accleration;
    int road_length;
    int road_width;
    int signal_length;
    char road_signal ;
    int truck_maxspeed;
    int truck_accleration;
    int bus_maxspeed;
    int bus_accleration;
    int bike_maxspeed;
    int bike_accleration;
    int time=40;
    string bike_color="RED";
    string truck_color="GREEN";
    string bus_color="BLUE";
    string car_color="BLUE";
    int auto_length;
    int auto_width;
    string auto_color="RED";
    int auto_maxspeed;
    int auto_accleration;
    int lane;
    bool check;
    int timepass;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
        throw std::runtime_error("file not found");
    
    int count =0;
    
    string s;
    string t;
    string v1;
    string v2;
    string v3;
    string v4;
    string v5;
    int jk;
    int pk;
    int temp;
    string sc;
    fin>>s;
    fin>>s;
    fin>>s;
    if((s.compare("1"))!=0)
    {
        cout<<"incorrect id"<<endl;
        return -1;
    }
    fin>>s;
    if(s.compare("Road_Length")==0)
    {
        fin>>t;
        fin>>road_length;
        fin>>s;
    }
    if(s.compare("Road_Width")==0)
    {
        fin>>t;
        fin>>road_width;
        fin>>s;
    }
    if(s.compare("Road_Signal")==0)
    {
        fin>>t;
        fin>>signal_length;
        fin>>s;
    }
    
    if(s.compare("Default_Length")==0)
    {
        fin>>t;
        fin>>temp;
        car_length=temp;
        bike_length=temp;
        bus_length=temp;
        truck_length=temp;
        auto_length= temp;
        fin>>s;
    }
    if(s.compare("Default_Width")==0)
    {
        fin>>t;
        fin>>temp;
        car_width=temp;
        bike_width=temp;
        bus_width=temp;
        truck_width=temp;
        auto_width=temp;
        fin>>s;
    }
    if(s.compare("Default_MaxSpeed")==0)
    {
        fin>>t;
        fin>>temp;
        car_maxspeed=temp;
        bike_maxspeed=temp;
        bus_maxspeed=temp;
        truck_maxspeed=temp;
        auto_maxspeed = temp;
        fin>>s;
    }
    if(s.compare("Default_Acceleration")==0)
    {
        fin>>t;
        fin>>temp;
        car_accleration=temp;
        bike_accleration=temp;
        bus_accleration=temp;
        truck_accleration=temp;
        auto_accleration = temp;
        fin>>s;
    }
    if(s.compare("Default_Color")==0)
    {
        fin>>t;
        fin>>t;
        car_color=t;
        bike_color=t;
        bus_color=t;
        truck_color=t;
        auto_color = t;
        fin>>s;
    }
    
    if(s.compare("Vehicle_Type")==0)
    {
        fin>>t;
        fin>>v1;
        fin>>s;
    }
    if(s.compare("Vehicle_Length")==0)
    {
        fin>>t;
        fin>>car_length;
        fin>>s;
    }
    if(s.compare("Vehicle_Width")==0)
    {
        fin>>t;
        fin>>car_width;
        fin>>s;
    }
    if(s.compare("Vehicle_MaxSpeed")==0)
    {
        fin>>t;
        fin>>car_maxspeed;
        fin>>s;
    }
    if(s.compare("Vehicle_Acceleration")==0)
    {
        fin>>t;
        fin>>car_accleration;
        fin>>s;
    }
    if(s.compare("Vehicle_Color")==0)
    {
        fin>>t;
        fin>>car_color;
        fin>>s;
    }
    
    if(s.compare("Vehicle_Type")==0)
    {
        fin>>t;
        fin>>v2;
        fin>>s;
    }
    if(s.compare("Vehicle_Length")==0)
    {
        fin>>t;
        fin>>bike_length;
        fin>>s;
    }
    if(s.compare("Vehicle_Width")==0)
    {
        fin>>t;
        fin>>bike_width;
        fin>>s;
    }
    if(s.compare("Vehicle_MaxSpeed")==0)
    {
        fin>>t;
        fin>>bike_maxspeed;
        fin>>s;
    }
    if(s.compare("Vehicle_Acceleration")==0)
    {
        fin>>t;
        fin>>bike_accleration;
        fin>>s;
    }
    if(s.compare("Vehicle_Color")==0)
    {
        fin>>t;
        fin>>bike_color;
        fin>>s;
    }
    
    if(s.compare("Vehicle_Type")==0)
    {
        fin>>t;
        fin>>v3;
        fin>>s;
    }
    if(s.compare("Vehicle_Length")==0)
    {
        fin>>t;
        fin>>bus_length;
        fin>>s;
    }
    if(s.compare("Vehicle_Width")==0)
    {
        fin>>t;
        fin>>bus_width;
        fin>>s;
    }
    if(s.compare("Vehicle_MaxSpeed")==0)
    {
        fin>>t;
        fin>>bus_maxspeed;
        fin>>s;
    }
    if(s.compare("Vehicle_Acceleration")==0)
    {
        fin>>t;
        fin>>bus_accleration;
        fin>>s;
    }
    if(s.compare("Vehicle_Color")==0)
    {
        fin>>t;
        fin>>bus_color;
        fin>>s;
    }
    
    if(s.compare("Vehicle_Type")==0)
    {
        fin>>t;
        fin>>v4;
        fin>>s;
    }
    if(s.compare("Vehicle_Length")==0)
    {
        fin>>t;
        fin>>truck_length;
        fin>>s;
    }
    if(s.compare("Vehicle_Width")==0)
    {
        fin>>t;
        fin>>truck_width;
        fin>>s;
    }
    if(s.compare("Vehicle_MaxSpeed")==0)
    {
        fin>>t;
        fin>>truck_maxspeed;
        fin>>s;
    }
    if(s.compare("Vehicle_Acceleration")==0)
    {
        fin>>t;
        fin>>truck_accleration;
        fin>>s;
    }
    if(s.compare("Vehicle_Color")==0)
    {
        fin>>t;
        fin>>truck_color;
        fin>>s;
    }
    
    if(s.compare("Vehicle_Type")==0)
    {
        fin>>t;
        fin>>v5;
        fin>>s;
    }
    if(s.compare("Vehicle_Length")==0)
    {
        fin>>t;
        fin>>auto_length;
        fin>>s;
    }
    if(s.compare("Vehicle_Width")==0)
    {
        fin>>t;
        fin>>auto_width;
        fin>>s;
    }
    if(s.compare("Vehicle_MaxSpeed")==0)
    {
        fin>>t;
        fin>>auto_maxspeed;
        fin>>s;
    }
    if(s.compare("Vehicle_Acceleration")==0)
    {
        fin>>t;
        fin>>auto_accleration;
        fin>>s;
    }
    if(s.compare("Vehicle_Color")==0)
    {
        fin>>t;
        fin>>auto_color;
        fin>>s;
    }
    
    
    
    if(s.compare("START")!=0)
        fin>>s;
    fin>>s;
    
    while((s.compare("END")!=0))
    {
        if(s.compare("bike")==0)
        {
            fin>>jk;
            data[0][count]=4*10+jk;
            count++;
            fin>>s;
        }
        else if(s.compare("Auto")==0)
        {
            fin>>jk;
            data[0][count]= 5*10+jk;
            count++;
            fin>>s;
        }
        else if(s.compare("Bus")==0)
        {
            fin>>jk;
            data[0][count]=3*10+jk;
            count++;
            fin>>s;
        }
        else  if(s.compare("Truck")==0)
        {
            fin>>jk;
            data[0][count]=2*10+jk;
            count++;
            fin>>s;
        }
        else if(s.compare("Car")==0)
        {
            fin>>jk;
            data[0][count]=10+jk;
            count++;
            fin>>s;
        }
        else if(s.compare("Pass")==0)
        {
            fin>>jk;
            data[0][count]=100+jk;
            count=count+jk;
            fin>>s;
        }
        else  if(s.compare("Signal")==0)
        {
            fin>>sc;
            if(sc.compare("RED")==0)
            {
                data[0][count]=7;
            }
            else if(sc.compare("GREEN")==0)
            {
                data[0][count]=8;
            }
            else
            {
                return -1;
            }
            count++;
            fin>>s;
        }
    }
    fin.close();

    float car_col[3];
    if(car_color.compare("RED")==0)
    {
        car_col[0]=1.0f;
        car_col[1]=0.0f;
        car_col[2]=0.0f;
    }
    else if(car_color.compare("GREEN")==0)
    {
        car_col[1]=1.0f;
        car_col[2]=0.0f;
        car_col[0]=0.0f;
    }
    else 
    {
        car_col[2]=1.0f;
        car_col[1]=0.0f;
        car_col[0]=0.0f;
    }
    float bike_col[3];
    if(bike_color.compare("RED")==0)
    {
        bike_col[0]=1.0f;
        bike_col[1]=0.0f;
        bike_col[2]=0.0f;
    }
    else if(bike_color.compare("GREEN")==0)
    {
        bike_col[1]=1.0f;
        bike_col[2]=0.0f;
        bike_col[0]=0.0f;
    }
    else 
    {
        bike_col[2]=1.0f;
        bike_col[1]=0.0f;
        bike_col[0]=0.0f;
    }
    float bus_col[3];
    if(bus_color.compare("RED")==0)
    {
        bus_col[0]=1.0f;
        bus_col[1]=0.0f;
        bus_col[2]=0.0f;
    }
    else if(bus_color.compare("GREEN")==0)
    {
        bus_col[1]=1.0f;
        bus_col[2]=0.0f;
        bus_col[0]=0.0f;
    }
    else 
    {
        bus_col[2]=1.0f;
        bus_col[1]=0.0f;
        bus_col[0]=0.0f;
    }
    float truck_col[3];
    if(truck_color.compare("RED")==0)
    {
        truck_col[0]=1.0f;
        truck_col[1]=0.0f;
        truck_col[2]=0.0f;
    }
    else if(truck_color.compare("GREEN")==0)
    {
        truck_col[1]=1.0f;
        truck_col[2]=0.0f;
        truck_col[0]=0.0f;
    }
    else 
    {
        truck_col[2]=1.0f;
        truck_col[1]=0.0f;
        truck_col[0]=0.0f;
    }
    float auto_col[3];
    if(auto_color.compare("RED")==0)
    {
        auto_col[0]=1.0f;
        auto_col[1]=0.0f;
        auto_col[2]=0.0f;
    }
    else if(auto_color.compare("GREEN")==0)
    {
        auto_col[1]=1.0f;
        auto_col[2]=0.0f;
        auto_col[0]=0.0f;
    }
    else 
    {
        auto_col[2]=1.0f;
        auto_col[1]=0.0f;
        auto_col[0]=0.0f;
    }
        //defining minimum seperation
    int bi_min_dist=2*bike_maxspeed*bike_maxspeed/(2*bike_accleration)+(bike_length);
    int b_min_dist=2*bus_maxspeed*bus_maxspeed/(2*bus_maxspeed)+(bus_length);
    int t_min_dist=2*truck_maxspeed*truck_maxspeed/(2*truck_accleration)+(truck_length);
    int c_min_dist=2*car_maxspeed*car_maxspeed/(2*car_accleration)+(car_length);
    int a_min_dist = 2*auto_maxspeed*auto_maxspeed/(2*auto_accleration)+(auto_length);
    //  cout << a_min_dist;
    int you = 0;
    
    char **V =new char*[road_length];
    for(int i=0;i<road_width;i++)
    {
        V[i]=new char[road_length];
    }
    
    char **W =new char*[road_length];   //duplicate output
    for(int i=0;i<road_width;i++)
    {
        W[i]=new char[road_length];
    }
    
    int **O =new int*[road_length];   //duplicate output
    for(int i=0;i<road_width;i++)
    {
        O[i]=new int[road_length];
    }
    
    int **M =new int*[road_length];
    for(int i=0;i<road_width;i++)
    {
        M[i]=new int[road_length];
    }
    
    for(int i=0;i<road_width;i++)
    {
        for(int j=0;j<road_length;j++)
        {
            V[i][j]=' ';
        }
    }
    for(int i=0;i<road_width;i++)
    {
        for(int j=0;j<road_length;j++)
        {
            O[i][j]=0;
        }
    }
    for(int i=0;i<road_width;i++)
    {
        for(int j=0;j<road_length;j++)
        {
            M[i][j]=0;
        }
    }
    //  cout<< auto_maxspeed;
    bool qa = true;
    bool qb = true;
    bool truth = true;
    int distance,speed,wo,po,f,g,fg,k,qwe,qwer,nm,bn,gn;
    int flag[road_width][road_length];
    int slag[road_width][road_length];
    for(int y=0;y<1000;y++)
    {
        qa=true;
        for(int p=y;p<100;p++)
        {
            if(data[0][p]!=0)
            {
                qa=false;
            }
        }
        for(int p=0;p<road_length;p++)
        {
            for(int q=0;q<road_width;q++)
            {
                if((V[q][p]!=' ')&&(road_signal!='R'))
                {
                    qa=false;
                }
            }
        }
        
        //inclusion of vechiles
        
        if(data[0][y]<10&&data[0][y]>0)
        {
            if(data[0][y]==7)
            {
                road_signal='R';
            }
            else if(data[0][y]==8)
            {
                road_signal='G';
            }
        }
        
        else if(data[0][y]<100)
        {
            check =true;
            
            if(data[0][y]>50)
            {
                lane = data[0][y]-51;
                for(int p=lane;p<lane+auto_width;p++)
                {
                    for(int q=0;q<auto_length+a_min_dist;q++)
                    {
                        if((p<road_width)&&(q<road_length)){
                            if(V[p][q]!=' ')
                            {
                                check = false;
                            }}
                        if(p>=road_width || q>=road_length)
                        {
                            check=false;
                        }
                    }
                }
                if(check)
                {
                    for(int p=lane;p<lane+auto_width;p++)
                    {
                        for(int q=0;q<auto_length;q++)
                        {
                            V[p][q]='a';
                            M[q][p]= auto_maxspeed;
                        }
                    }
                }
            }
            
            
            else
                if(data[0][y]>40)
                {
                    lane = data[0][y]-41;
                    for(int p=lane;p<lane+bike_width;p++)
                    {
                        for(int q=0;q<bike_length+bi_min_dist;q++)
                        {
                            if((p<road_width)&&(q<road_length)){
                                if(V[p][q]!=' ')
                                {
                                    check = false;
                                }}
                            if(p>=road_width)
                            {
                                check=false;
                            }
                        }
                    }
                    if(check)
                    {
                        for(int p=lane;p<lane+bike_width;p++)
                        {
                            for(int q=0;q<bike_length;q++)
                            {
                                V[p][q]='B';
                                M[q][p]= bike_maxspeed;
                            }
                        }
                    }
                }
                else if(data[0][y]>30)
                {
                    lane = data[0][y]-31;
                    for(int p=lane;p<lane+bus_width;p++)
                    {
                        for(int q=0;q<bus_length+b_min_dist;q++)
                        {
                            if((p<road_width)&&(q<road_length))
                            {
                                if(V[p][q]!=' ')
                                {
                                    check = false;
                                }
                            }
                            if(p>=road_width)
                                check =false;
                        }
                    }
                    if(check)
                    {
                        for(int p=lane;p<lane+bus_width;p++)
                        {
                            for(int q=0;q<bus_length;q++)
                            {
                                V[p][q]='b';
                                M[q][p]=bus_maxspeed;
                            }
                        }
                    }
                }
                else if(data[0][y]>20)
                {
                    lane = data[0][y]-21;
                    for(int p=lane;p<lane+truck_width;p++)
                    {
                        for(int q=0;q<truck_length+t_min_dist;q++)
                        {
                            if(V[p][q]!=' ')
                            {if((p<road_width)&&(q<road_length)){
                                check = false;
                            }}
                            if(p>=road_width)
                                check = false;
                        }
                    }
                    if(check)
                    {
                        for(int p=lane;p<lane+truck_width;p++)
                        {
                            for(int q=0;q<truck_length;q++)
                            {
                                V[p][q]='t';
                                M[p][q]=truck_maxspeed;
                            }
                        }
                    }
                }
            
                else if(data[0][y]>10)
                {
                    lane = data[0][y]-11;
                    for(int p=lane;p<lane+car_width;p++)
                    {
                        for(int q=0;q<car_length+c_min_dist;q++)
                        {if((p<road_width)&&(q<road_length)){
                            if(V[p][q]!=' ')
                            {
                                check = false;
                            }}
                            if(p>=road_width)
                                check = false;
                        }
                    }
                    if(check)
                    {
                        for(int p=lane;p<lane+car_width;p++)
                        {
                            for(int q=0;q<car_length;q++)
                            {
                                V[p][q]='c';
                                M[p][q]=car_maxspeed;
                            }
                        }
                    }
                }
            
        }
        else if(data[0][y]>100)
        {
            timepass=data[0][y]-100;
        }
        else
        {
            ;
        }
        
        //calculation of remaining vechiles
        
        int rf=0,tg=0,yh=0,uj=0;
        for(int po=0;po<road_width;po++)
        {
            for(int qo=0;qo<road_length;qo++)
            {
                if(V[po][qo]=='c')
                {
                    rf = rf+1;
                }
                else if(V[po][qo]=='t')
                {
                    tg = tg+1;
                }
                else if(V[po][qo]=='b')
                {
                    yh = yh+1;
                }
                else if(V[po][qo]=='B')
                {
                    uj = uj+1;
                }
            }
        }
        int fgh = rf/(car_length*car_width)+tg/(truck_width*truck_length)+yh/(bus_width*bus_length)+uj/(bike_width*bike_length);
        
        cout << endl;
        cout <<"Time:"<<y+1;
        cout << endl;
        for(int i=0;i<road_width;i++)
        {
            for(int j=0;j<road_length;j++)
            {
                cout << V[i][j];
                W[i][j]=V[i][j];
                if(j==signal_length)
                    cout<<"-";
            }
            cout <<endl;
        }
        
        int n=0;    //total no of vehicles

        if(!glfwInit()) //initialize glfw
        {
            cout<<"Failed to initialize GLFW."<<endl;
            //return -1;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  //version
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);  //version
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  //take newest version
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //forward compatible

        GLFWwindow* window = glfwCreateWindow(1500, 2000*road_width/road_length, "TRAFFIC", NULL, NULL); //window properties
        if (window == NULL)
        {
            cout<<"Failed to create GLFW window"<<endl;
            glfwTerminate();
            //return -1;
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))    //initialize glad
        {
            cout<<"Failed to initialize GLAD" <<endl;
           // return -1;
        }

        // vertex shader
        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        // fragment shader
        int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        // link shaders
        int shader = glCreateProgram();
        glAttachShader(shader, vertexShader);
        glAttachShader(shader, fragmentShader);
        glLinkProgram(shader);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
       
        //float *vertices = new float[24*l*w];    //normalised coordinates and color
        float vertices[240000]=
        {    
             -1.0f+2.0f*((float(signal_length)+1.0f)/float(road_length)),  1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
             -1.0f+2.0f*((float(signal_length)+1.0f)/float(road_length)), -1.0f, 0.0f, 1.0f, 0.0f, 0.0f
        };
        
        unsigned int indices[60000] = 
        {  //start from 0
            0,1
            //3, 4, 5,   
            //6, 7, 8    
        };


        for(int j=road_length-1;j>=0;j--)
        {
            for(int i=0;i<road_width;i++)
            {
                if(W[i][j]=='B')
                {   if((O[i][j]==0)&&((M[i][j]!=0)||(road_signal!='R')))//false
                    {
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1)+0.2f)/float(road_length));//24
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.2f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=bike_col[0];
                        vertices[24*n+16]=bike_col[1];
                        vertices[24*n+17]=bike_col[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(bike_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13];
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=bike_col[0];
                        vertices[24*n+22]=bike_col[1];
                        vertices[24*n+23]=bike_col[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(bike_length)-0.4f)/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(bike_width)-0.4f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=bike_col[0];
                        vertices[24*n+28]=bike_col[1];
                        vertices[24*n+29]=bike_col[2];
                        vertices[24*n+30]=vertices[24*n+12];
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(bike_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=bike_col[0];
                        vertices[24*n+34]=bike_col[1];
                        vertices[24*n+35]=bike_col[2];
                    }
                    else
                    {
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1))/float(road_length));//24
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.4f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=bike_col[0];
                        vertices[24*n+16]=bike_col[1];
                        vertices[24*n+17]=bike_col[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(bike_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13] + (0.8f/float(road_width));
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=bike_col[0];
                        vertices[24*n+22]=bike_col[1];
                        vertices[24*n+23]=bike_col[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(bike_length))/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(bike_width)-0.8f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=bike_col[0];
                        vertices[24*n+28]=bike_col[1];
                        vertices[24*n+29]=bike_col[2];
                        vertices[24*n+30]=vertices[24*n+12] - (0.8f/float(road_length));
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(bike_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=bike_col[0];
                        vertices[24*n+34]=bike_col[1];
                        vertices[24*n+35]=bike_col[2];                   
                    }
                    indices[6*n+2]=4*n+2;
                    indices[6*n+3]=4*n+3;
                    indices[6*n+4]=4*n+4;
                    indices[6*n+5]=4*n+2;
                    indices[6*n+6]=4*n+4;
                    indices[6*n+7]=4*n+5;
                    n=n+1;
                    for(int k=i;k<i+bike_width;k++)
                    {
                        for(int l=j;l>j-bike_length;l--)
                        {
                            W[k][l]=' ';
                        }
                    }
                }
                else if(W[i][j]=='b')
                {
                    if(O[i][j]==0)
                    {
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1)+0.2f)/float(road_length));//24
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.2f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=bus_color[0];
                        vertices[24*n+16]=bus_color[1];
                        vertices[24*n+17]=bus_color[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(bus_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13];
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=bus_color[0];
                        vertices[24*n+22]=bus_color[1];
                        vertices[24*n+23]=bus_color[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(bus_length)-0.4f)/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(bus_width)-0.4f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=bus_color[0];
                        vertices[24*n+28]=bus_color[1];
                        vertices[24*n+29]=bus_color[2];
                        vertices[24*n+30]=vertices[24*n+12];
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(bus_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=bus_color[0];
                        vertices[24*n+34]=bus_color[1];
                        vertices[24*n+35]=bus_color[2];
                    }
                    else
                    {
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1))/float(road_length));//24
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.4f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=bus_col[0];
                        vertices[24*n+16]=bus_col[1];
                        vertices[24*n+17]=bus_col[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(bus_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13] + (0.8f/float(road_width));
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=bus_col[0];
                        vertices[24*n+22]=bus_col[1];
                        vertices[24*n+23]=bus_col[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(bus_length))/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(bus_width)-0.8f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=bus_col[0];
                        vertices[24*n+28]=bus_col[1];
                        vertices[24*n+29]=bus_col[2];
                        vertices[24*n+30]=vertices[24*n+12] - (0.8f/float(road_length));
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(bus_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=bus_col[0];
                        vertices[24*n+34]=bus_col[1];
                        vertices[24*n+35]=bus_col[2];                   
                    }
                    indices[6*n+2]=4*n+2;//6
                    indices[6*n+3]=4*n+3;
                    indices[6*n+4]=4*n+4;
                    indices[6*n+5]=4*n+2;
                    indices[6*n+6]=4*n+4;
                    indices[6*n+7]=4*n+5;
                    n=n+1;
                    for(int k=i;k<i+truck_width;k++)
                    {
                        for(int l=j;l>j-truck_length;l--)
                        {
                            W[k][l]=' ';
                        }
                    }
                }
                else if(W[i][j]=='c')
                {
                    if(O[i][j]==0)
                    {
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1)+0.2f)/float(road_length));//24
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.2f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=car_col[0];
                        vertices[24*n+16]=car_col[1];
                        vertices[24*n+17]=car_col[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(car_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13];
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=car_col[0];
                        vertices[24*n+22]=car_col[1];
                        vertices[24*n+23]=car_col[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(car_length)-0.4f)/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(car_width)-0.4f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=car_col[0];
                        vertices[24*n+28]=car_col[1];
                        vertices[24*n+29]=car_col[2];
                        vertices[24*n+30]=vertices[24*n+12];
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(car_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=car_col[0];
                        vertices[24*n+34]=car_col[1];
                        vertices[24*n+35]=car_col[2];
                    }
                    else
                    {
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1))/float(road_length));//24
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.4f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=car_col[0];
                        vertices[24*n+16]=car_col[1];
                        vertices[24*n+17]=car_col[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(car_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13] + (0.8f/float(road_width));
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=car_col[0];
                        vertices[24*n+22]=car_col[1];
                        vertices[24*n+23]=car_col[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(car_length))/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(car_width)-0.8f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=car_col[0];
                        vertices[24*n+28]=car_col[1];
                        vertices[24*n+29]=car_col[2];
                        vertices[24*n+30]=vertices[24*n+12] - (0.8f/float(road_length));
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(car_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=car_col[0];
                        vertices[24*n+34]=car_col[1];
                        vertices[24*n+35]=car_col[2];  
                    }   
                    indices[6*n+2]=4*n+2;//6
                    indices[6*n+3]=4*n+3;
                    indices[6*n+4]=4*n+4;
                    indices[6*n+5]=4*n+2;
                    indices[6*n+6]=4*n+4;
                    indices[6*n+7]=4*n+5;
                    n=n+1;
                    for(int k=i;k<i+car_width;k++)
                    {
                        for(int l=j;l>j-car_length;l--)
                        {
                            W[k][l]=' ';
                        }
                    }
                 }
                else if(W[i][j]=='t')
                {
                    if(O[i][j]==0)
                    {    
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1)+0.2f)/float(road_length));//24
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.2f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=truck_col[0];
                        vertices[24*n+16]=truck_col[1];
                        vertices[24*n+17]=truck_col[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(truck_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13];
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=truck_col[0];
                        vertices[24*n+22]=truck_col[1];
                        vertices[24*n+23]=truck_col[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(truck_length)-0.4f)/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(truck_width)-0.4f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=truck_col[0];
                        vertices[24*n+28]=truck_col[1];
                        vertices[24*n+29]=truck_col[2];
                        vertices[24*n+30]=vertices[24*n+12];
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(truck_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=truck_col[0];
                        vertices[24*n+34]=truck_col[1];
                        vertices[24*n+35]=truck_col[2];
                    }
                    else
                    {
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1))/float(road_length));//24
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.4f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=truck_col[0];
                        vertices[24*n+16]=truck_col[1];
                        vertices[24*n+17]=truck_col[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(truck_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13] + (0.8f/float(road_width));
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=truck_col[0];
                        vertices[24*n+22]=truck_col[1];
                        vertices[24*n+23]=truck_col[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(truck_length))/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(truck_width)-0.8f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=truck_col[0];
                        vertices[24*n+28]=truck_col[1];
                        vertices[24*n+29]=truck_col[2];
                        vertices[24*n+30]=vertices[24*n+12] - (0.8f/float(road_length));
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(truck_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=truck_col[0];
                        vertices[24*n+34]=truck_col[1];
                        vertices[24*n+35]=truck_col[2];
                    } 
                    indices[6*n+2]=4*n+2;
                    indices[6*n+3]=4*n+3;
                    indices[6*n+4]=4*n+4;
                    indices[6*n+5]=4*n+2;
                    indices[6*n+6]=4*n+4;
                    indices[6*n+7]=4*n+5;
                    n=n+1;
                    for(int k=i;k<i+truck_width;k++)
                    {
                        for(int l=j;l>j-truck_length;l--)
                        {
                            W[k][l]=' ';
                        }
                    }               
                }
                else if(W[i][j]=='a')
                {
                    if((O[i][j]==0)&&((M[i][j]!=0)||(road_signal!='R')))
                    { 
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1)+0.2f)/float(road_length));
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.2f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=auto_col[0];
                        vertices[24*n+16]=auto_col[1];
                        vertices[24*n+17]=auto_col[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(auto_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13];
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=auto_col[0];
                        vertices[24*n+22]=auto_col[1];
                        vertices[24*n+23]=auto_col[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(auto_length)-0.4f)/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(auto_width)-0.4f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=auto_col[0];
                        vertices[24*n+28]=auto_col[1];
                        vertices[24*n+29]=auto_col[2];
                        vertices[24*n+30]=vertices[24*n+12];
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(auto_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=auto_col[0];
                        vertices[24*n+34]=auto_col[1];
                        vertices[24*n+35]=auto_col[2];
                    }
                    else
                    {
                        vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1))/float(road_length));//24
                        vertices[24*n+13]=1.0f-2.0f*((float(i)+0.4f)/float(road_width));
                        vertices[24*n+14]=0.0f;
                        vertices[24*n+15]=auto_col[0];
                        vertices[24*n+16]=auto_col[1];
                        vertices[24*n+17]=auto_col[2];
                        vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(auto_length)-0.4f)/float(road_length));
                        vertices[24*n+19]=vertices[24*n+13] + (0.8f/float(road_width));
                        vertices[24*n+20]=0.0f;
                        vertices[24*n+21]=auto_col[0];
                        vertices[24*n+22]=auto_col[1];
                        vertices[24*n+23]=auto_col[2];
                        vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(auto_length))/float(road_length));
                        vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(auto_width)-0.8f)/float(road_width));
                        vertices[24*n+26]=0.0f;
                        vertices[24*n+27]=auto_col[0];
                        vertices[24*n+28]=auto_col[1];
                        vertices[24*n+29]=auto_col[2];
                        vertices[24*n+30]=vertices[24*n+12] - (0.8f/float(road_length));
                        vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(auto_width)-0.4f)/float(road_width));
                        vertices[24*n+32]=0.0f;
                        vertices[24*n+33]=auto_col[0];
                        vertices[24*n+34]=auto_col[1];
                        vertices[24*n+35]=auto_col[2];
                    }
                    indices[6*n+2]=4*n+2;
                    indices[6*n+3]=4*n+3;
                    indices[6*n+4]=4*n+4;
                    indices[6*n+5]=4*n+2;
                    indices[6*n+6]=4*n+4;
                    indices[6*n+7]=4*n+5;
                    n=n+1;
                    for(int k=i;k<i+auto_width;k++)
                    {
                        for(int l=j;l>j-auto_length;l--)
                        {
                            W[k][l]=' ';
                        }
                    }               
                }
                else
                {
                    ;
                }
            }
        }

        unsigned int VBO, VAO, EBO; //vertex buffer object, Vertex Array Object, element buffer object
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        //position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
        glEnableVertexAttribArray(0);

         // color
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0); 

        // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        //glBindVertexArray(0); 

        while (!glfwWindowShouldClose(window))
        {      
            Input(window);    // input
            glClearColor(0.3f, 0.3f, 0.3f, 1.0f);   //background color
            glClear(GL_COLOR_BUFFER_BIT);   //retain background color

            glUseProgram(shader);
            glBindVertexArray(VAO);

            glDrawElements(GL_TRIANGLES, 6*n+2, GL_UNSIGNED_INT, (void*)(2 * sizeof(float)));    //number of total vertices
            glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, 0); //traffic light line
     
            // swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
        
        if(qa)
        {
            cout<< "Simulation time" << "  "<< (y+1) << "|" << "Simulation Id" << "  "<< 1 <<"|"<< "No. of remaining vechiles" << "  "<< fgh<<endl;
            break;
        }
        
        sleep_for(milliseconds(250));
        // flag decleation
        for(int i=0;i<road_width;i++)
        {
            for(int j=0;j<road_length;j++)
            {
                flag[i][j]=0;
            }
        }
        
        for(int i=0;i<road_width;i++)
        {
            for(int j=0;j<road_length;j++)
            {
                slag[i][j]=0;
            }
        }
        for(int i=0;i<road_width;i++)
        {
            for(int j=0;j<road_length;j++)
            {
                O[i][j]=0;
            }
        }
        //function to find position of every vechile for next time
        
        for(int i=0;i<road_width;i++)
        {
            for(int j=0;j<road_length;j++)
            {
                if(flag[i][j]==0)
                {
                    f=-1; g=-1;
                    truth = true;
                    if(V[i][j]=='c')
                    {
                        f=j;
                        g=i;
                        bool w = true;
                        bool x = true;
                        for(int p=f+car_length;p<f+car_length+c_min_dist;p++)
                        {
                            for(int q=g;q<g+car_width;q++)
                            {
                                if((q<road_width)&&(p<road_length))
                                {
                                    if(V[q][p]!=' ')
                                    {
                                        x = false;
                                    }
                                }
                            }
                        }
                        
                        if(road_signal=='R'&&j+c_min_dist>signal_length&& j<signal_length)
                        {
                            x=false;
                        }
                        if(x)
                        {
                            if(M[i][j]<car_maxspeed)//if vechile has sufficient space infront of it and has speed less then maxspeed
                            {
                                if((M[i][j]+car_accleration)>car_maxspeed)
                                {
                                    int diff= car_maxspeed- M[i][j];
                                    float ratio = diff/car_accleration;
                                    distance = M[i][j]*ratio + car_accleration*ratio*ratio/2 + car_maxspeed*(1-ratio);
                                    distance= floor(distance);
                                    for(int p=f;p<f+car_length;p++)
                                    {
                                        for(int q=g;q<g+car_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+car_length+distance;p++)
                                    {
                                        for(int q=g;q<g+car_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='c';
                                                M[q][q]=car_maxspeed;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    distance=M[i][j]+car_accleration/2;
                                    for(int p=f;p<f+car_length;p++)
                                    {
                                        for(int q=g;q<g+car_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+car_length+distance;p++)
                                    {
                                        for(int q=g;q<g+car_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='c';
                                                M[q][p]=M[i][j]+car_accleration;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                distance = car_maxspeed;
                                for(int p=f;p<f+car_length;p++)
                                {
                                    
                                    for(int q=g;q<g+car_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]=' ';
                                            M[q][p]=0;
                                        }
                                    }
                                }
                                for(int p=f+distance;p<f+car_length+distance;p++)
                                {
                                    for(int q=g;q<g+car_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]='c';
                                            M[q][p]=car_maxspeed;
                                            flag[q][p]=1;
                                        }
                                    }
                                }
                            }
                        }
                        else//if donot have sufficient space
                        {
                            x=true;
                            for(int p=f+car_length;p<(f+car_length+c_min_dist);p++)
                            {
                                for(int q=g+1;q<g+1+car_width;q++)
                                {
                                    if((q<road_width)&&(p<road_length))
                                    {
                                        if(V[q][p]!=' ')
                                        {
                                            x = false;
                                        }
                                    }
                                }
                            }
                            if(road_signal=='R'&&j+c_min_dist>signal_length&&j<=signal_length)//if signal is red
                            {
                                x=false;
                            }
                            
                            for(int p=0;p<f;p++)//checker for right overtake
                            {
                                for(int q=g+1;q<g+1+car_width;q++)
                                {
                                    if(q<road_width&&p<road_length){
                                        if(V[q][p]!=' ')
                                        {
                                            if(V[q][p]=='c')
                                            {
                                                if((p+M[q][p]+c_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='t')
                                            {
                                                if((p+M[q][p]+t_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='a')
                                            {
                                                if((p+M[q][p]+a_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='b')
                                            {
                                                if((p+M[q][p]+b_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='B')
                                            {
                                                if((p+M[q][p]+bi_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                        }}
                                    if(q>=road_width)
                                    {
                                        x=false;
                                    }
                                }
                            }
                            
                            if(x)//vechile will overtake
                            {
                                if(M[i][j]==car_maxspeed)
                                {
                                    distance = car_maxspeed;
                                    for(int p=f;p<f+car_length;p++)
                                    {
                                        for(int q=g;q<g+car_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+car_length+distance;p++)
                                    {
                                        for(int q=g+1;q<1+g+car_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='c';
                                                M[q][p]=car_maxspeed;
                                                flag[q][p]=1;
                                                O[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                
                                else
                                {
                                    if((M[i][j]+car_accleration)>car_maxspeed)
                                    {
                                        int diff= car_maxspeed- M[i][j];
                                        float ratio = diff/car_accleration;
                                        distance = M[i][j]*ratio + car_accleration*ratio*ratio/2 + car_maxspeed*(1-ratio);
                                        distance= floor(distance);
                                        for(int p=f;p<f+car_length;p++)
                                        {
                                            for(int q=g;q<g+car_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+car_length+distance;p++)
                                        {
                                            for(int q=g+1;q<1+g+car_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='c';
                                                    M[q][p]=car_maxspeed;
                                                    flag[q][p]=1;
                                                    O[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        distance=M[i][j]+car_accleration/2;
                                        for(int p=f;p<f+car_length;p++)
                                        {
                                            for(int q=g;q<g+car_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+car_length+distance;p++)
                                        {
                                            for(int q=g+1;q<g+1+car_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='c';
                                                    M[q][p]=M[i][j]+car_accleration;
                                                    flag[q][p]=1;
                                                    O[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else//if donot have space as well as donot able to overtake
                            {
                                qwe = M[i][j]-car_accleration;
                                
                                if(qwe<0)
                                {
                                    qwe=0;
                                }
                                distance = M[i][j]-car_accleration/2;
                                if(distance<0){
                                    distance =0;}
                                
                                
                                
                                for(int p=f+car_length;p<f+car_length+distance;p++)
                                {
                                    for(int q=g;q<g+car_width;q++)
                                    {if(p<road_length&&q<road_width){
                                        if(V[q][p]!=' ')
                                        {
                                            w=false;
                                        }}
                                    }
                                }
                                
                                for(int p=f;p<f+car_length;p++)
                                {
                                    for(int q=g;q<g+car_width;q++)
                                    {if(q<road_width&&p<road_length){
                                        V[q][p]=' ';
                                        M[q][p]=0;
                                    }}
                                }
                                
                                if(w)
                                {
                                    for(int p=f+distance;p<f+distance+car_length;p++)
                                    {
                                        for(int q=g;q<g+car_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='c';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }
                                
                                else
                                {
                                    for(int p=f;p<f+car_length;p++)
                                    {
                                        for(int q=g;q<g+car_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='c';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }
                                
                                
                            }
                        }
                    }
                    
                    else if(V[i][j]=='t')
                    {
                        f=j;
                        g=i;
                        bool w = true;
                        bool x = true;
                        for(int p=f+truck_length;p<f+truck_length+t_min_dist;p++)
                        {
                            for(int q=g;q<g+truck_width;q++)
                            {
                                if((q<road_width)&&(p<road_length))
                                {
                                    if(V[q][p]!=' ')
                                    {
                                        x = false;
                                    }
                                }
                            }
                        }
                        
                        if(road_signal=='R'&&j+t_min_dist>signal_length&& j<signal_length)
                        {
                            x=false;
                        }
                        if(x)
                        {
                            if(M[i][j]<truck_maxspeed)
                            {
                                if((M[i][j]+truck_accleration)>truck_maxspeed)
                                {
                                    int diff= truck_maxspeed- M[i][j];
                                    float ratio = diff/truck_accleration;
                                    distance = M[i][j]*ratio + truck_accleration*ratio*ratio/2 + truck_maxspeed*(1-ratio);
                                    distance= floor(distance);
                                    for(int p=f;p<f+truck_length;p++)
                                    {
                                        for(int q=g;q<g+truck_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+truck_length+distance;p++)
                                    {
                                        for(int q=g;q<g+truck_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='t';
                                                M[q][q]=truck_maxspeed;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    distance=M[i][j]+truck_accleration/2;
                                    for(int p=f;p<f+truck_length;p++)
                                    {
                                        for(int q=g;q<g+truck_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+truck_length+distance;p++)
                                    {
                                        for(int q=g;q<g+truck_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='t';
                                                M[q][p]=M[i][j]+truck_accleration;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                distance = truck_maxspeed;
                                for(int p=f;p<f+truck_length;p++)
                                {
                                    
                                    for(int q=g;q<g+truck_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]=' ';
                                            M[q][p]=0;
                                        }
                                    }
                                }
                                for(int p=f+distance;p<f+truck_length+distance;p++)
                                {
                                    for(int q=g;q<g+truck_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]='t';
                                            M[q][p]=truck_maxspeed;
                                            flag[q][p]=1;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            x=true;
                            for(int p=f+truck_length;p<(f+truck_length+t_min_dist);p++)
                            {
                                for(int q=g+1;q<g+1+truck_width;q++)
                                {
                                    if((q<road_width)&&(p<road_length))
                                    {
                                        if(V[q][p]!=' ')
                                        {
                                            x = false;
                                        }
                                    }
                                }
                            }
                            if(road_signal=='R'&&j+t_min_dist>signal_length&&j<=signal_length)
                            {
                                x=false;
                            }
                            
                            for(int p=0;p<f;p++)
                            {
                                for(int q=g+1;q<g+1+truck_width;q++)
                                {
                                    if(q<road_width&&p<road_length){
                                        if(V[q][p]!=' ')
                                        {
                                            if(V[q][p]=='c')
                                            {
                                                if((p+M[q][p]+c_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='t')
                                            {
                                                if((p+M[q][p]+t_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='b')
                                            {
                                                if((p+M[q][p]+b_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='a')
                                            {
                                                if((p+M[q][p]+a_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='B')
                                            {
                                                if((p+M[q][p]+bi_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                        }}
                                    if(q==road_width)
                                    {
                                        // cout<<"car";
                                        x=false;
                                    }
                                }
                            }
                            
                            if(x)
                            {
                                if(M[i][j]==truck_maxspeed)
                                {
                                    distance = truck_maxspeed;
                                    for(int p=f;p<f+truck_length;p++)
                                    {
                                        for(int q=g;q<g+truck_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+truck_length+distance;p++)
                                    {
                                        for(int q=g+1;q<1+g+truck_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='t';
                                                M[q][p]=truck_maxspeed;
                                                flag[q][p]=1;
                                                O[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                
                                else
                                {
                                    if((M[i][j]+truck_accleration)>truck_maxspeed)
                                    {
                                        int diff= truck_maxspeed- M[i][j];
                                        float ratio = diff/truck_accleration;
                                        distance = M[i][j]*ratio + truck_accleration*ratio*ratio/2 + truck_maxspeed*(1-ratio);
                                        distance= floor(distance);
                                        for(int p=f;p<f+truck_length;p++)
                                        {
                                            for(int q=g;q<g+truck_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+truck_length+distance;p++)
                                        {
                                            for(int q=g+1;q<1+g+truck_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='t';
                                                    M[q][p]=truck_maxspeed;
                                                    flag[q][p]=1;
                                                    O[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        distance=M[i][j]+truck_accleration/2;
                                        for(int p=f;p<f+truck_length;p++)
                                        {
                                            for(int q=g;q<g+truck_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+truck_length+distance;p++)
                                        {
                                            for(int q=g+1;q<g+1+truck_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='t';
                                                    M[q][p]=M[i][j]+truck_accleration;
                                                    flag[q][p]=1;
                                                    O[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                
                                
                                qwe = M[i][j]-truck_accleration;
                                
                                if(qwe<0)
                                {
                                    qwe=0;
                                }
                                distance = M[i][j]-truck_accleration/2;
                                if(distance<0)
                                {
                                    distance =0;
                                }
                                
                                
                                
                                for(int p=f+truck_length;p<f+truck_length+distance;p++)
                                {
                                    for(int q=g;q<g+truck_width;q++)
                                    {if(p<road_length&&q<road_width){
                                        if(V[q][p]!=' ')
                                        {
                                            w=false;
                                        }}
                                    }
                                }
                                
                                for(int p=f;p<f+truck_length;p++)
                                {
                                    for(int q=g;q<g+truck_width;q++)
                                    {if(q<road_width&&p<road_length){
                                        V[q][p]=' ';
                                        M[q][p]=0;
                                    }}
                                }
                                
                                if(w)
                                {
                                    
                                    for(int p=f+distance;p<f+distance+truck_length;p++)
                                    {
                                        for(int q=g;q<g+truck_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='t';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }
                                
                                else
                                {
                                    for(int p=f;p<f+truck_length;p++)
                                    {
                                        for(int q=g;q<g+truck_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='t';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }
                                
                                
                            }
                        }
                    }
                    
                    
                    
                    
                    else if(V[i][j]=='a')
                    {
                        f=j;
                        g=i;
                        bool w = true;
                        bool x = true;
                        for(int p=f+auto_length;p<f+auto_length+a_min_dist;p++)
                        {
                            for(int q=g;q<g+auto_width;q++)
                            {
                                if((q<road_width)&&(p<road_length))
                                {
                                    if(V[q][p]!=' ')
                                    {
                                        x = false;
                                    }
                                }
                            }
                        }
                        
                        // cout<<road_signal;
                        // cout<<j;
                        //cout<<j+a_min_dist;
                        if(road_signal=='R'&&j+a_min_dist>signal_length&& j<signal_length)
                        {
                            x=false;
                        }
                        if(x)
                        { // cout<<"you";
                            if(M[i][j]<auto_maxspeed)
                            {
                                if((M[i][j]+auto_accleration)>auto_maxspeed)
                                {
                                    int diff= auto_maxspeed- M[i][j];
                                    float ratio = diff/auto_accleration;
                                    distance = M[i][j]*ratio + auto_accleration*ratio*ratio/2 + auto_maxspeed*(1-ratio);
                                    distance= floor(distance);
                                    for(int p=f;p<f+auto_length;p++)
                                    {
                                        for(int q=g;q<g+auto_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+auto_length+distance;p++)
                                    {
                                        for(int q=g;q<g+auto_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='a';
                                                M[q][q]=auto_maxspeed;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    distance=M[i][j]+auto_accleration/2;
                                    for(int p=f;p<f+auto_length;p++)
                                    {
                                        for(int q=g;q<g+auto_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+auto_length+distance;p++)
                                    {
                                        for(int q=g;q<g+auto_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='a';
                                                M[q][p]=M[i][j]+auto_accleration;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                distance = auto_maxspeed;
                                for(int p=f;p<f+auto_length;p++)
                                {
                                    
                                    for(int q=g;q<g+auto_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]=' ';
                                            M[q][p]=0;
                                        }
                                    }
                                }
                                for(int p=f+distance;p<f+auto_length+distance;p++)
                                {
                                    for(int q=g;q<g+auto_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]='a';
                                            M[q][p]=auto_maxspeed;
                                            flag[q][p]=1;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            // cout<<"sd";
                            x=true;
                            for(int p=f+auto_length;p<(f+auto_length+a_min_dist);p++)
                            {
                                for(int q=g+1;q<g+1+auto_width;q++)
                                {
                                    if((q<road_width)&&(p<road_length))
                                    {
                                        if(V[q][p]!=' ')
                                        {
                                            x = false;
                                        }
                                    }
                                }
                            }
                            if(road_signal=='R'&&j+a_min_dist>signal_length&&j<=signal_length)
                            {
                                x=false;
                            }
                            
                            for(int p=0;p<f;p++)
                            {
                                for(int q=g+1;q<g+1+auto_width;q++)
                                {
                                    if(q<road_width&&p<road_length){
                                        if(V[q][p]!=' ')
                                        {
                                            if(V[q][p]=='c')
                                            {
                                                if((p+M[q][p]+c_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='t')
                                            {
                                                if((p+M[q][p]+t_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='a')
                                            {
                                                if((p+M[q][p]+a_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='b')
                                            {
                                                if((p+M[q][p]+b_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            
                                            else if(V[q][p]=='B')
                                            {
                                                if((p+M[q][p]+bi_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                        }}
                                    if(q==road_width)
                                    {
                                        x=false;
                                    }
                                }
                            }
                            
                            if(x)
                            {
                                if(M[i][j]==auto_maxspeed)
                                {
                                    distance = auto_maxspeed;
                                    for(int p=f;p<f+auto_length;p++)
                                    {
                                        for(int q=g;q<g+auto_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+auto_length+distance;p++)
                                    {
                                        for(int q=g+1;q<1+g+auto_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='a';
                                                M[q][p]=auto_maxspeed;
                                                flag[q][p]=1;
                                                O[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                
                                else
                                {
                                    if((M[i][j]+auto_accleration)>auto_maxspeed)
                                    {
                                        int diff= auto_maxspeed- M[i][j];
                                        float ratio = diff/auto_accleration;
                                        distance = M[i][j]*ratio + auto_accleration*ratio*ratio/2 + auto_maxspeed*(1-ratio);
                                        distance= floor(distance);
                                        for(int p=f;p<f+auto_length;p++)
                                        {
                                            for(int q=g;q<g+auto_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+auto_length+distance;p++)
                                        {
                                            for(int q=g+1;q<1+g+auto_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='a';
                                                    M[q][p]=auto_maxspeed;
                                                    flag[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        distance=M[i][j]+auto_accleration/2;
                                        for(int p=f;p<f+auto_length;p++)
                                        {
                                            for(int q=g;q<g+auto_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+auto_length+distance;p++)
                                        {
                                            for(int q=g+1;q<g+1+auto_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='a';
                                                    M[q][p]=M[i][j]+auto_accleration;
                                                    flag[q][p]=1;
                                                    O[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                
                                
                                qwe = M[i][j]-auto_accleration;
                                
                                if(qwe<0)
                                {
                                    qwe=0;
                                }
                                distance = M[i][j]-auto_accleration/2;
                                if(distance<0)
                                {
                                    distance =0;
                                }
                                
                                
                                
                                for(int p=f+auto_length;p<f+auto_length+distance;p++)
                                {
                                    for(int q=g;q<g+auto_width;q++)
                                    {if(p<road_length&&q<road_width){
                                        if(V[q][p]!=' ')
                                        {
                                            w=false;
                                        }}
                                    }
                                }
                                
                                for(int p=f;p<f+auto_length;p++)
                                {
                                    for(int q=g;q<g+auto_width;q++)
                                    {if(q<road_width&&p<road_length){
                                        V[q][p]=' ';
                                        M[q][p]=0;
                                    }}
                                }
                                
                                if(w)
                                {
                                    
                                    for(int p=f+distance;p<f+distance+auto_length;p++)
                                    {
                                        for(int q=g;q<g+auto_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='a';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }
                                
                                else
                                {
                                    for(int p=f;p<f+auto_length;p++)
                                    {
                                        for(int q=g;q<g+auto_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='a';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }
                                
                                
                            }
                        }
                    }
                    
                    
                    
                    
                    
                    else    if(V[i][j]=='b')
                    {
                        f=j;
                        g=i;
                        bool w = true;
                        bool x = true;
                        for(int p=f+bus_length;p<f+bus_length+b_min_dist;p++)
                        {
                            for(int q=g;q<g+bus_width;q++)
                            {
                                if((q<road_width)&&(p<road_length))
                                {
                                    if(V[q][p]!=' ')
                                    {
                                        x = false;
                                    }
                                }
                            }
                        }
                        
                        if(road_signal=='R'&&j+b_min_dist>signal_length&& j<signal_length)
                        {
                            x=false;
                        }
                        if(x)
                        {
                            if(M[i][j]<bus_maxspeed)
                            {
                                if((M[i][j]+bus_accleration)>bus_maxspeed)
                                {
                                    int diff= bus_maxspeed- M[i][j];
                                    float ratio = diff/bus_accleration;
                                    distance = M[i][j]*ratio + bus_accleration*ratio*ratio/2 + bus_maxspeed*(1-ratio);
                                    distance= floor(distance);
                                    for(int p=f;p<f+bus_length;p++)
                                    {
                                        for(int q=g;q<g+bus_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+bus_length+distance;p++)
                                    {
                                        for(int q=g;q<g+bus_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='b';
                                                M[q][q]=bus_maxspeed;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    distance=M[i][j]+bus_accleration/2;
                                    for(int p=f;p<f+bus_length;p++)
                                    {
                                        for(int q=g;q<g+bus_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+bus_length+distance;p++)
                                    {
                                        for(int q=g;q<g+bus_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='b';
                                                M[q][p]=M[i][j]+bus_accleration;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                distance = bus_maxspeed;
                                for(int p=f;p<f+bus_length;p++)
                                {
                                    
                                    for(int q=g;q<g+bus_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]=' ';
                                            M[q][p]=0;
                                        }
                                    }
                                }
                                for(int p=f+distance;p<f+bus_length+distance;p++)
                                {
                                    for(int q=g;q<g+bus_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]='b';
                                            M[q][p]=bus_maxspeed;
                                            flag[q][p]=1;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            x=true;
                            for(int p=f+bus_length;p<(f+bus_length+b_min_dist);p++)
                            {
                                for(int q=g+1;q<g+1+bus_width;q++)
                                {
                                    if((q<road_width)&&(p<road_length))
                                    {
                                        if(V[q][p]!=' ')
                                        {
                                            x = false;
                                        }
                                    }
                                }
                            }
                            if(road_signal=='R'&&j+b_min_dist>signal_length&&j<=signal_length)
                            {
                                x=false;
                            }
                            
                            for(int p=0;p<f;p++)
                            {
                                for(int q=g+1;q<g+1+bus_width;q++)
                                {
                                    if(q<road_width&&p<road_length){
                                        if(V[q][p]!=' ')
                                        {
                                            if(V[q][p]=='c')
                                            {
                                                if((p+M[q][p]+c_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='b')
                                            {
                                                if((p+M[q][p]+b_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='a')
                                            {
                                                if((p+M[q][p]+a_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='t')
                                            {
                                                if((p+M[q][p]+t_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='B')
                                            {
                                                if((p+M[q][p]+bi_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                        }}
                                    if(q>=road_width)
                                    {
                                        x=false;
                                    }
                                }
                            }
                            
                            if(x)
                            {
                                if(M[i][j]==bus_maxspeed)
                                {
                                    distance = bus_maxspeed;
                                    for(int p=f;p<f+bus_length;p++)
                                    {
                                        for(int q=g;q<g+bus_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+bus_length+distance;p++)
                                    {
                                        for(int q=g+1;q<1+g+bus_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='b';
                                                M[q][p]=bus_maxspeed;
                                                flag[q][p]=1;
                                                O[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                
                                else
                                {
                                    if((M[i][j]+bus_accleration)>bus_maxspeed)
                                    {
                                        int diff= bus_maxspeed- M[i][j];
                                        float ratio = diff/bus_accleration;
                                        distance = M[i][j]*ratio + bus_accleration*ratio*ratio/2 + bus_maxspeed*(1-ratio);
                                        distance= floor(distance);
                                        for(int p=f;p<f+bus_length;p++)
                                        {
                                            for(int q=g;q<g+bus_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+bus_length+distance;p++)
                                        {
                                            for(int q=g+1;q<1+g+bus_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='b';
                                                    M[q][p]=bus_maxspeed;
                                                    flag[q][p]=1;
                                                    O[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        distance=M[i][j]+bus_accleration/2;
                                        for(int p=f;p<f+bus_length;p++)
                                        {
                                            for(int q=g;q<g+bus_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+bus_length+distance;p++)
                                        {
                                            for(int q=g+1;q<g+1+bus_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='b';
                                                    M[q][p]=M[i][j]+bus_accleration;
                                                    flag[q][p]=1;
                                                    O[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                
                                
                                qwe = M[i][j]-bus_accleration;
                                
                                if(qwe<0)
                                {
                                    qwe=0;
                                }
                                distance = M[i][j]-bus_accleration/2;
                                if(distance<0){
                                    distance =0;}
                                
                                
                                
                                
                                for(int p=f+bus_length;p<f+bus_length+distance;p++)
                                {
                                    for(int q=g;q<g+bus_width;q++)
                                    {if(p<road_length&&q<road_width){
                                        if(V[q][p]!=' ')
                                        {
                                            w=false;
                                        }}
                                    }
                                }
                                
                                for(int p=f;p<f+bus_length;p++)
                                {
                                    for(int q=g;q<g+bus_width;q++)
                                    {if(q<road_width&&p<road_length){
                                        V[q][p]=' ';
                                        M[q][p]=0;
                                    }}
                                }
                                
                                if(w)
                                {
                                    
                                    
                                    
                                    
                                    for(int p=f+distance;p<f+distance+bus_length;p++)
                                    {
                                        for(int q=g;q<g+bus_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='b';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }
                                
                                else
                                {
                                    for(int p=f;p<f+bus_length;p++)
                                    {
                                        for(int q=g;q<g+bus_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='b';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }
                                
                                
                            }
                        }
                    }
                    
                    
                    
                    else    if(V[i][j]=='B')
                    {
                        f=j;
                        g=i;
                        bool w = true;
                        bool x = true;
                        for(int p=f+bike_length;p<f+bike_length+bi_min_dist;p++)
                        {
                            for(int q=g;q<g+bike_width;q++)
                            {
                                if((q<road_width)&&(p<road_length))
                                {
                                    if(V[q][p]!=' ')
                                    {
                                        x = false;
                                    }
                                }
                            }
                        }
                        
                        if(road_signal=='R'&&j+bi_min_dist>signal_length&& j<signal_length)
                        {
                            x=false;
                        }
                        if(x)
                        {
                            if(M[i][j]<bike_maxspeed)
                            {
                                if((M[i][j]+bike_accleration)>bike_maxspeed)
                                {
                                    int diff= bike_maxspeed- M[i][j];
                                    float ratio = diff/bike_accleration;
                                    distance = M[i][j]*ratio + bike_accleration*ratio*ratio/2 + bike_maxspeed*(1-ratio);
                                    distance = floor(distance);
                                    for(int p=f;p<f+bike_length;p++)
                                    {
                                        for(int q=g;q<g+bike_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+bike_length+distance;p++)
                                    {
                                        for(int q=g;q<g+bike_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='B';
                                                M[q][q]=bike_maxspeed;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    distance=M[i][j]+bike_accleration/2;
                                    for(int p=f;p<f+bike_length;p++)
                                    {
                                        for(int q=g;q<g+bike_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+bike_length+distance;p++)
                                    {
                                        for(int q=g;q<g+bike_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='B';
                                                M[q][p]=M[i][j]+bike_accleration;
                                                flag[q][p]=1;
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                distance = bike_maxspeed;
                                for(int p=f;p<f+bike_length;p++)
                                {
                                    //  cout<<"rahul";
                                    for(int q=g;q<g+bike_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]=' ';
                                            M[q][p]=0;
                                        }
                                    }
                                }
                                for(int p=f+distance;p<f+bike_length+distance;p++)
                                {
                                    for(int q=g;q<g+bike_width;q++)
                                    {
                                        if((q<road_width)&&(p<road_length))
                                        {
                                            V[q][p]='B';
                                            M[q][p]=bike_maxspeed;
                                            flag[q][p]=1;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            x=true;
                            for(int p=f+bike_length;p<(f+bike_length+bi_min_dist);p++)
                            {
                                for(int q=g+1;q<g+1+bike_width;q++)
                                {
                                    if((q<road_width)&&(p<road_length))
                                    {
                                        if(V[q][p]!=' ')
                                        {
                                            x = false;
                                        }
                                    }
                                }
                            }
                            if(road_signal=='R'&&j+bi_min_dist>signal_length&&j<=signal_length)
                            {
                                x=false;
                            }
                            
                            for(int p=0;p<f;p++)
                            {
                                for(int q=g+1;q<g+1+bike_width;q++)
                                {
                                    if(q<road_width&&p<road_length){
                                        if(V[q][p]!=' ')
                                        {
                                            if(V[q][p]=='c')
                                            {
                                                if((p+M[q][p]+c_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='t')
                                            {
                                                if((p+M[q][p]+t_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='b')
                                            {
                                                if((p+M[q][p]+b_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='a')
                                            {
                                                if((p+M[q][p]+a_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                            else if(V[q][p]=='B')
                                            {
                                                if((p+M[q][p]+bi_min_dist)>(f+M[i][j]))
                                                {
                                                    x=false;
                                                }
                                            }
                                        }}
                                    if(q>=road_width)
                                    {
                                        x=false;
                                    }
                                }
                            }
                            
                            if(x)
                            {
                                if(M[i][j]==bike_maxspeed)
                                {
                                    distance = bike_maxspeed;
                                    for(int p=f;p<f+bike_length;p++)
                                    {
                                        for(int q=g;q<g+bike_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]=' ';
                                                M[q][p]=0;
                                            }
                                        }
                                    }
                                    for(int p=f+distance;p<f+bike_length+distance;p++)
                                    {
                                        for(int q=g+1;q<1+g+bike_width;q++)
                                        {
                                            if((q<road_width)&&(p<road_length))
                                            {
                                                V[q][p]='B';
                                                M[q][p]=bike_maxspeed;
                                                flag[q][p]=1;
                                                O[q][p]=1;
                                            }
                                        }
                                    }
                                }
                                
                                else
                                {
                                    if((M[i][j]+bike_accleration)>bike_maxspeed)
                                    {
                                        int diff= bike_maxspeed- M[i][j];
                                        float ratio = diff/bike_accleration;
                                        distance = M[i][j]*ratio + bike_accleration*ratio*ratio/2 + bike_maxspeed*(1-ratio);
                                        distance= floor(distance);
                                        for(int p=f;p<f+bike_length;p++)
                                        {
                                            for(int q=g;q<g+bike_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+bike_length+distance;p++)
                                        {
                                            for(int q=g+1;q<1+g+bike_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='B';
                                                    M[q][p]=bike_maxspeed;
                                                    flag[q][p]=1;
                                                    O[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        distance=M[i][j]+bike_accleration/2;
                                        for(int p=f;p<f+bike_length;p++)
                                        {
                                            for(int q=g;q<g+bike_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]=' ';
                                                    M[q][p]=0;
                                                }
                                            }
                                        }
                                        for(int p=f+distance;p<f+bike_length+distance;p++)
                                        {
                                            for(int q=g+1;q<g+1+bike_width;q++)
                                            {
                                                if((q<road_width)&&(p<road_length))
                                                {
                                                    V[q][p]='B';
                                                    M[q][p]=M[i][j]+bike_accleration;
                                                    flag[q][p]=1;
                                                    O[q][p]=1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                
                                
                                qwe = M[i][j]-bike_accleration;
                                // cout <<qwe;
                                if(qwe<0)
                                {
                                    qwe=0;
                                }
                                distance = M[i][j]-bike_accleration/2;
                                if(distance<0){
                                    distance =0;}
                                
                                
                                
                                
                                for(int p=f+bike_length;p<f+bike_length+distance;p++)
                                {
                                    for(int q=g;q<g+bike_width;q++)
                                    {if(p<road_length&&q<road_width){
                                        if(V[q][p]!=' ')
                                        {
                                            w=false;
                                        }}
                                    }
                                }
                                
                                for(int p=f;p<f+bike_length;p++)
                                {
                                    for(int q=g;q<g+bike_width;q++)
                                    {
                                        if(q<road_width&&p<road_length){
                                            V[q][p]=' ';
                                            M[q][p]=0;
                                        }
                                    }
                                }
                                
                                if(w)
                                {
                                    for(int p=f+distance;p<f+distance+bike_length;p++)
                                    {
                                        for(int q=g;q<g+bike_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='B';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }
                                
                                else
                                {
                                    for(int p=f;p<f+bike_length;p++)
                                    {
                                        for(int q=g;q<g+bike_width;q++)
                                        {
                                            if(p<road_length&&q<road_width){
                                                V[q][p]='B';
                                                flag[q][p]=1;
                                                M[q][p]=qwe;}
                                        }
                                    }
                                }                                                                
                            }
                        }
                    }
                    
                }
            }
        }
    }
    return 0;
}

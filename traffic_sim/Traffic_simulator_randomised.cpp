#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cmath>
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
int main()
{
    using namespace std::this_thread;
    using namespace std::chrono;
 
    int truck_width=2;
    int truck_length=3;
    int bus_length=3;
    int bus_width=2;
    int bike_length=2;
    int bike_width=1;
    int car_length=2;
    int car_width=2;
    int car_maxspeed=2;
    int car_accleration=2;
    int road_length=100;
    int road_width=6;
    int signal_length=60;
    char road_signal = 'R';
    int truck_maxspeed=2;
    int truck_accleration=2;
    int bus_maxspeed=2;
    int bus_accleration=2;
    int bike_maxspeed=2;
    int bike_accleration=2;
    int time=60;
    
    

    
    
    int bi_min_dist=bike_maxspeed*bike_maxspeed/(2*bike_accleration)+bike_accleration;
    int b_min_dist=bus_maxspeed*bus_maxspeed/(2*bus_maxspeed)+bus_accleration;
    int t_min_dist=truck_maxspeed*truck_maxspeed/(2*truck_accleration)+truck_accleration;
    int c_min_dist=car_maxspeed*car_maxspeed/(2*car_accleration)+car_accleration;
    
    
   
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
            M[i][j]=0;
        }
    }
    
    
    
    int distance,speed,temp,wo,po,f,g,fg,k,qwe,qwer,nm,bn,gn;
    int flag[road_width][road_length];
    for(int y=0;y<time;y++){
        
        
        if(y>time/2)
        {
            road_signal='Y';
        }
        else{
            road_signal='R';
        }
      
        
        
        for(int i=0;i<road_width;i++)
        {
            int qw = rand()%5;
           
            if(qw==0)
            {
                bool b =true;
                for(int p=i;p<i+truck_width;p++)
                {
                    for(int q=0;q<truck_length+t_min_dist;q++)
                    {
                        
                        if((p>=road_width))
                        {
                            b=false;
                            break;
                        }    if(V[p][q]!=' ')
                        {
                            b= false;
                        }
                        
                    }
                }
               
                if(b)
                {
                    for(int k=0;k<truck_length;k++)
                    {
                        for(int j=i;j<i+truck_width;j++)
                        {
                            if((j<road_width))
                            {
                                V[j][k]='t';
                                M[j][k]=truck_maxspeed;
                            }
                        }
                    }
                }
            }
            else if(qw==1)
            {
                bool b =true;
                for(int p=i;p<i+car_width;p++)
                {
                    for(int q=0;q<car_length+c_min_dist;q++)
                    {
                        if((p>=road_width))
                        {
                            b=false;break;
                        }
                        if(V[p][q]!=' ')
                        {
                            b= false;
                        }
                        
                    }
                }
                
                if(b)
                {
                    for(int k=0;k<car_length;k++)
                    {
                        for(int j=i;j<i+car_width;j++)
                        {
                            if((j<road_length))
                            {
                                V[j][k]='c';
                                M[j][k]=car_maxspeed;
                            }
                        }
                    }
                }
            }
            else if(qw==2)
            {
                bool b =true;
                for(int p=i;p<i+bus_width;p++)
                {
                    for(int q=0;q<bus_length+b_min_dist;q++)
                    {
                        if((p>=road_width))
                        {
                            b=false;break;
                        }
                        if(V[p][q]!=' ')
                        {
                            b= false;
                        }
                        
                        
                    }
                }
                
                if(b)
                {
                    for(int k=0;k<bus_length;k++)
                    {
                        for(int j=i;j<i+bus_width;j++)
                        {
                            if((j<road_width))
                            {
                                V[j][k]='b';
                                M[j][k]=bus_maxspeed;
                            }
                        }
                    }
                }
            }
            else if(qw==3)
            {
                bool b =true;
                for(int p=i;p<i+bike_width;p++)
                {
                    for(int q=0;q<bike_length+bi_min_dist;q++)
                    {
                        if((p>=road_width))
                        {
                            b=false;break;
                        }
                        if(V[p][q]!=' ')
                        {
                            b= false;
                        }
                        
                    }
                }
                if(b)
                {
                    for(int k=0;k<bike_length;k++)
                    {
                        for(int j=i;j<i+bike_width;j++)
                        {
                            if((j<road_width))
                            {
                                V[j][k]='B';
                                M[j][k]=bike_maxspeed;
                            }
                        }
                    }
                }
            }
            else
            {
                
            }
        }
        
        
        
        cout << endl;
        cout <<"Time:"<<y+1;
        cout << endl;
        for(int i=0;i<road_width;i++)
        {
            for(int j=0;j<road_length;j++)
            {
                cout << V[i][j];
                W[i][j]=V[i][j];
                if(j==signal_length+1)
                    cout<<"-";
            }
            cout <<endl;
        }
        
    int n=0;    // no of vehicles

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
    float vertices[24000]=
    {    
         -1.0f+2.0f*((float(signal_length)+2.0f)/float(road_length)),  1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
         -1.0f+2.0f*((float(signal_length)+2.0f)/float(road_length)), -1.0f, 0.0f, 1.0f, 0.0f, 0.0f
    };
    
    unsigned int indices[6000] = 
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
            {   //cout<<"b";
                vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1)+0.1f)/float(road_length));//24
                vertices[24*n+13]=1.0f-2.0f*((float(i)+0.1f)/float(road_width));
                vertices[24*n+14]=0.0f;
                vertices[24*n+15]=0.0f;
                vertices[24*n+16]=0.0f;
                vertices[24*n+17]=1.0f;
                vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(bike_length)-0.2f)/float(road_length));
                vertices[24*n+19]=vertices[24*n+13];
                vertices[24*n+20]=0.0f;
                vertices[24*n+21]=0.0f;
                vertices[24*n+22]=0.0f;
                vertices[24*n+23]=1.0f;
                vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(bike_length)-0.2f)/float(road_length));
                vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(bike_width)-0.2f)/float(road_width));
                vertices[24*n+26]=0.0f;
                vertices[24*n+27]=0.0f;
                vertices[24*n+28]=0.0f;
                vertices[24*n+29]=1.0f;
                vertices[24*n+30]=vertices[24*n+12];
                vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(bike_width)-0.2f)/float(road_width));
                vertices[24*n+32]=0.0f;
                vertices[24*n+33]=0.0f;
                vertices[24*n+34]=0.0f;
                vertices[24*n+35]=1.0f;
                indices[6*n+2]=4*n+2;//6
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
                vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1)+0.1f)/float(road_length));//24
                vertices[24*n+13]=1.0f-2.0f*((float(i)+0.1f)/float(road_width));
                vertices[24*n+14]=0.0f;
                vertices[24*n+15]=0.0f;
                vertices[24*n+16]=0.0f;
                vertices[24*n+17]=1.0f;
                vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(bus_length)-0.2f)/float(road_length));
                vertices[24*n+19]=vertices[24*n+13];
                vertices[24*n+20]=0.0f;
                vertices[24*n+21]=0.0f;
                vertices[24*n+22]=0.0f;
                vertices[24*n+23]=1.0f;
                vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(bus_length)-0.2f)/float(road_length));
                vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(bus_width)-0.2f)/float(road_width));
                vertices[24*n+26]=0.0f;
                vertices[24*n+27]=0.0f;
                vertices[24*n+28]=0.0f;
                vertices[24*n+29]=1.0f;
                vertices[24*n+30]=vertices[24*n+12];
                vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(bus_width)-0.2f)/float(road_width));
                vertices[24*n+32]=0.0f;
                vertices[24*n+33]=0.0f;
                vertices[24*n+34]=0.0f;
                vertices[24*n+35]=1.0f;
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
            else if(W[i][j]=='c')
            {
                vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1)+0.1f)/float(road_length));//24
                vertices[24*n+13]=1.0f-2.0f*((float(i)+0.1f)/float(road_width));
                vertices[24*n+14]=0.0f;
                vertices[24*n+15]=0.0f;
                vertices[24*n+16]=1.0f;
                vertices[24*n+17]=0.0f;
                vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(car_length)-0.2f)/float(road_length));
                vertices[24*n+19]=vertices[24*n+13];
                vertices[24*n+20]=0.0f;
                vertices[24*n+21]=0.0f;
                vertices[24*n+22]=1.0f;
                vertices[24*n+23]=0.0f;
                vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(car_length)-0.2f)/float(road_length));
                vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(car_width)-0.2f)/float(road_width));
                vertices[24*n+26]=0.0f;
                vertices[24*n+27]=0.0f;
                vertices[24*n+28]=1.0f;
                vertices[24*n+29]=0.0f;
                vertices[24*n+30]=vertices[24*n+12];
                vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(car_width)-0.2f)/float(road_width));
                vertices[24*n+32]=0.0f;
                vertices[24*n+33]=0.0f;
                vertices[24*n+34]=1.0f;
                vertices[24*n+35]=0.0f;
                indices[6*n+2]=4*n+2;
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
                //cout<<"t";
                vertices[24*n+12]=1.0f-2.0f*((float(road_length-j-1)+0.1f)/float(road_length));//24
                vertices[24*n+13]=1.0f-2.0f*((float(i)+0.1f)/float(road_width));
                vertices[24*n+14]=0.0f;
                vertices[24*n+15]=0.0f;
                vertices[24*n+16]=1.0f;
                vertices[24*n+17]=0.0f;
                vertices[24*n+18]=vertices[24*n+12]-2.0f*((float(truck_length)-0.2f)/float(road_length));
                vertices[24*n+19]=vertices[24*n+13];
                vertices[24*n+20]=0.0f;
                vertices[24*n+21]=0.0f;
                vertices[24*n+22]=1.0f;
                vertices[24*n+23]=0.0f;
                vertices[24*n+24]=vertices[24*n+12]-2.0f*((float(truck_length)-0.2f)/float(road_length));
                vertices[24*n+25]=vertices[24*n+13]-2.0f*((float(truck_width)-0.2f)/float(road_width));
                vertices[24*n+26]=0.0f;
                vertices[24*n+27]=0.0f;
                vertices[24*n+28]=1.0f;
                vertices[24*n+29]=0.0f;
                vertices[24*n+30]=vertices[24*n+12];
                vertices[24*n+31]=vertices[24*n+13]-2.0f*((float(truck_width)-0.2f)/float(road_width));
                vertices[24*n+32]=0.0f;
                vertices[24*n+33]=0.0f;
                vertices[24*n+34]=1.0f;
                vertices[24*n+35]=0.0f;
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
     
        
    sleep_for(milliseconds(250));
        
        
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
                if(flag[i][j]==0)
                {
                    f=-1; g=-1;
                    
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
                            if(M[i][j]<car_maxspeed)
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
                        else
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
                            if(road_signal=='R'&&j+c_min_dist>signal_length&&j<=signal_length)
                            {
                                x=false;
                            }
                            
                            for(int p=0;p<f;p++)
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
                            
                            if(x)
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
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
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
                                if(distance<0){
                                    distance =0;}
                         
                                
                                
                                
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
                                if(distance<0)
                                {
                                    distance =0;

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
                                    {if(q<road_width&&p<road_length){
                                        V[q][p]=' ';
                                        M[q][p]=0;
                                    }}
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
    }
    return 0;
}

//
//  verkada.cpp
//  Practice
//
//  Created by Dexter's Lab on 1/21/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include <algorithm>
using namespace std;
/*
Verkada Light sensor question

Background
==========
Security cameras often have an Ambient Light Sensor (ALS) which measures the amount of light around the camera and triggers a "night mode" when the ambient light is too low.

You've been given an ALS that reports sensor readings using the following struct:
  typedef struct SensorReading {
    int status;
    float lux;
    uint64_t timestamp; // time of reading
  } SensorReading;
  
To get a sensor reading, call:
SensorReading read_next_sample(uint64_t max_wait) { ... }
This function is blocking!  It doesn't return a value until either max_wait microseconds have elapsed or the ALS returns a new value.  The SensorReading.status int indicates whether the value changed (VALID) or not (NO_CHANGE).

(We've implemented a mock version of read_next_sample below, but you do not need to read the code and understand it to complete this task).

Task
====
Working with blocking functions is hard and not thread-friendly, so we want to wrap the ALS function in a non-blocking, thread-safe way.
Design and implement an API that allows users to read lux values from any time within the last 10 minutes.  Your API should be non-blocking and thread-safe.
*/

/* Status enum */
enum Status {
  ERROR = 0,
  NO_CHANGE = 1,
  VALID = 2,
};

/* Don't edit this code */
struct SensorReading {
  int status;
  float lux;
  uint64_t timestamp;
};

class sensorData
{
    private:
        queue<SensorReading> q;
        time_t currTime;
        mutex mtx;
        
        time_t getCurrentTime()
        {
            return time(nullptr);
        }
        
    public:
        sensorData()
        {
            currTime = time(nullptr);
        }
        
        bool isAvailable(){
            if(q.empty())
                return true;
            else
                return false;
        }
        
        void addData(SensorReading reading)
        {
            mtx.lock();
            q.push(reading);
            mtx.unlock();
        }
        
        SensorReading getData()
        {
            mtx.lock();
            if(q.empty())
            {
                mtx.unlock();
                return SensorReading{ERROR, 0.0, 0};
            }
            
            SensorReading dat = q.front();
            currTime = getCurrentTime();
            while(!q.empty() && dat.timestamp > (currTime - 10) )
            {
                q.pop();
                dat = q.front();
            }
            
            if(q.empty()){
                mtx.unlock();
                return SensorReading{ERROR, 0.0, 0};
            }
            q.pop();
            mtx.unlock();
            return dat;
        }
};

/* these functions are provided for you; no need to implement */
uint64_t get_timestamp();
SensorReading read_next_sample(uint64_t max_wait);

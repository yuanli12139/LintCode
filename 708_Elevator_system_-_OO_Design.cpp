/*
708. Elevator system - OO Design
题目：为一栋大楼设计电梯系统

不需要考虑超重的情况
该电梯系统目前只有1台电梯, 该楼共有n层
每台电梯有三种状态：上升，下降，空闲
当电梯往一个方向移动时，在电梯内无法按反向的楼层
我们提供了其他几个已经实现好的类，你只需要实现Elevator Class内的部分函数即可。

Example
5           // 电梯一共有5层
ExternalRequest(3, "Down")
ExternalRequest(2, "Up")
openGate()
InternalRequest(1)
closeGate()
openGate()
closeGate()
openGate()
closeGate()

// 注意每行命令之后我们都会调用elevatorStatusDescription 函数，用于测试你是否处于一个正确的状态。

你能看到的正确的内容应该是：

Currently elevator status is : DOWN.
Current level is at: 1.
up stop list looks like: [false, false, false, false, false].
down stop list looks like:  [false, false, true, false, false].
*****************************************

Currently elevator status is : DOWN.
Current level is at: 1.
up stop list looks like: [false, true, false, false, false].
down stop list looks like:  [false, false, true, false, false].
*****************************************

Currently elevator status is : DOWN.
Current level is at: 3.
up stop list looks like: [false, true, false, false, false].
down stop list looks like:  [false, false, false, false, false].
*****************************************

Currently elevator status is : DOWN.
Current level is at: 3.
up stop list looks like: [false, true, false, false, false].
down stop list looks like:  [true, false, false, false, false].
*****************************************

Currently elevator status is : DOWN.
Current level is at: 3.
up stop list looks like: [false, true, false, false, false].
down stop list looks like:  [true, false, false, false, false].
*****************************************

Currently elevator status is : DOWN.
Current level is at: 1.
up stop list looks like: [false, true, false, false, false].
down stop list looks like:  [false, false, false, false, false].
*****************************************

Currently elevator status is : UP.
Current level is at: 1.
up stop list looks like: [false, true, false, false, false].
down stop list looks like:  [false, false, false, false, false].
*****************************************

Currently elevator status is : UP.
Current level is at: 2.
up stop list looks like: [false, false, false, false, false].
down stop list looks like:  [false, false, false, false, false].
*****************************************

Currently elevator status is : IDLE.
Current level is at: 2.
up stop list looks like: [false, false, false, false, false].
down stop list looks like:  [false, false, false, false, false].
*****************************************


Author: Yuan Li
Date: 8/19/2018 
Difficulty: Hard
*/

class Elevator;
class ExternalRequest;
class InternalRequest;

enum Direction {
    _UP, _DOWN
};

enum Status {
    UP, DOWN, IDLE
};

class Request {
  private:
    int level;

  public:
    Request(int l = 0) {
        level = l;
    }
    
    int getLevel() {
        return level;
    }
};

class ElevatorButton {
  private:
    int level;
    Elevator *elevator;

  public:
    ElevatorButton(int level, Elevator *e) {
        this->level = level;
        this->elevator = e;
    }

    void pressButton();
};

class ExternalRequest : public Request {
  private:
    Direction direction;

  public:
    ExternalRequest() {
        
    }
    
    ExternalRequest(int l, Direction d) : Request(l) {
        // TODO Auto-generated constructor stub
        this->direction = d;
    }

    Direction getDirection() {
        return direction;
    }
};

class InternalRequest : public Request {
  public:
    InternalRequest(int l = 0) : Request(l) {
        // TODO Auto-generated constructor stub
    }
};

string writeVector(vector<bool>& vec) {
    string temp = Lib::writeVector(vec);
    for(auto ch = temp.begin(); ch != temp.end(); ++ch) {
        if((*ch) == ',') {
            ch = temp.insert(++ch, ' ');
        }
    }
    return temp;
}

class Elevator {
  private:
    vector<ElevatorButton> buttons;
    vector<bool> upStops;
    vector<bool> downStops;
    int currLevel;
    Status status;

  public:
    Elevator(int n) {
        status = IDLE;
        for (int i = 0; i < n; ++i) {
            upStops.push_back(false);
            downStops.push_back(false);
        }
    }

    void insertButton(ElevatorButton eb) {
        buttons.push_back(eb);
    }

    void handleExternalRequest(ExternalRequest r) {
        // Write your code here
        if (r.getDirection() == _UP) {
            upStops[r.getLevel()-1] = true;
            if (noRequests(downStops)) {
                status = UP;
            }
        } else {
            downStops[r.getLevel()-1] = true;
            if (noRequests(upStops)) {
                status = DOWN;
            }
        }
    }

    void handleInternalRequest(InternalRequest r) {
        // Write your code here
        if (status == UP) {
            if (r.getLevel() - 1 >= currLevel) {
                upStops[r.getLevel()-1] = true;
            }
        } else if (status == DOWN) {
            if (r.getLevel() - 1 <= currLevel) {
                downStops[r.getLevel()-1] = true;
            }
        }
    }

    void openGate() {
        // Write your code here
        if (status == UP) {
            for (int i = 0; i < upStops.size(); ++i) {
                // keep going up or pick up at the lowerest level of request
                int pickUpLevel = (currLevel + i) % upStops.size();
                
                if (upStops[pickUpLevel]) {
                    upStops[pickUpLevel] = false;
                    currLevel = pickUpLevel;
                    break;
                }
            }
        } else if (status == DOWN) {
            for (int i = 0; i < downStops.size(); ++i) {
                // keep going down or pick up at the highest level of request
                int pickUpLevel = (currLevel + downStops.size() - i) % downStops.size();
                
                if (downStops[pickUpLevel]) {
                    downStops[pickUpLevel] = false;
                    currLevel = pickUpLevel;
                    break;
                }
            }
        }
    }

    void closeGate() {
        // Write your code here
        if (status == IDLE) {
            if (noRequests(downStops)) {
                status = UP;
                return;
            }
            if (noRequests(upStops)) {
                status = DOWN;
                return;
            }
            
        } else if (status == UP) {
            if (noRequests(upStops)) {
                if (noRequests(downStops)) {
                    status = IDLE;
                } else {
                    status = DOWN;
                }
            }
        } else {
            if (noRequests(downStops)) {
                if (noRequests(upStops)) {
                    status = IDLE;
                } else {
                    status = UP;
                }
            }
        }
    }
    
    bool noRequests(vector<bool>& stops) {
        for (int i = 0; i < stops.size(); ++i)
        {
            if (stops[i])
            {
                return false;
            }
        }
        return true;
    }

    string elevatorStatusDescription() {
        string status_;
        if(status == UP) {
            status_ = "UP";
        }
        else if(status == DOWN) {
            status_ = "DOWN";
        }
        else if(status == IDLE) {
            status_ = "IDLE";
        }
        string description = "Currently elevator status is : " + status_ 
                + ".\nCurrent level is at: " + Utility::toString(currLevel + 1)
                + ".\nup stop list looks like: " + writeVector(upStops)
                + ".\ndown stop list looks like:  " + writeVector(downStops)
                + ".\n*****************************************\n";
        //cout << description << endl;
        return description;
    }
};

void ElevatorButton::pressButton() {
    InternalRequest request = InternalRequest(level);
    elevator->handleInternalRequest(request);
}

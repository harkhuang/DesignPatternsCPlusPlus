#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

class OrdBook;

/*
 * Event
 * defines an updating interface for objects that should be notified
 * of changes in a OrdBook
 */
class Event
{
public:
  virtual ~Event() {}
  
  virtual int getState() = 0;
  virtual void update( OrdBook *OrdBook ) = 0;
  // ...
};

/*
 * Concrete Event
 * stores state of interest to AlgEvent objects and
 * sends a notification to its observers when its state changes
 */
class AlgEvent : public Event
{
public:
  AlgEvent( const int state ) :
    observer_state( state ) {}
  
  ~AlgEvent() {}
  
  int getState()
  {
    return observer_state;
  }
  
  void update( OrdBook *OrdBook );
  // ...

private:
  int observer_state;
  // ...
};

/*
 * OrdBook
 * knows its observers and provides an interface for attaching
 * and detaching observers
 */
class OrdBook
{
public:
  virtual ~OrdBook() {}
  
  void attach( Event *Event )
  {
    observers.push_back(Event);
  }
  
  void detach( const int index )
  {
    observers.erase( observers.begin() + index );
  }
  
  // 行情接口主动回调该接口
  void notify()
  {
    for ( unsigned int i = 0; i < observers.size(); i++ )
    {
      observers.at( i )->update( this );
    }
  }
  
  virtual int getState() = 0;
  virtual void setState( const int s ) = 0;
  // ...

private:
  std::vector<Event*> observers;
  
  // ...
};





// 定制后的算法单类型
class ConcreteSubject : public OrdBook
{
public:
  ~ConcreteSubject() {}
  
  int getState()
  {
    return subject_state;
  }
  
  void setState( const int s )
  {
    subject_state = s;
  }
  
  // 输出最上层母单
  std::string pop() {
    _childOrders.pop_back();
  };

private:
  int subject_state;

  std::list<std::string >  _childOrders;
};

void AlgEvent::update( OrdBook *OrdBook )
{
  observer_state = OrdBook->getState();
  std::cout << "Event state updated." << std::endl;
}


int main()
{


  // 注册两个算法事件
  AlgEvent observer1( 1 );
  AlgEvent observer2( 2 );
  

  // 获取观察者状态
  std::cout << "Event 1 state: " << observer1.getState() << std::endl;
  std::cout << "Event 2 state: " << observer2.getState() << std::endl;
  


  // 根据时间注册母单
  OrdBook *OrdBook = new ConcreteSubject();
  OrdBook->attach( &observer1 );
  OrdBook->attach( &observer2 );
  
  // 母单在行情/回报的回调函数中的调用方式
  OrdBook->setState( 10 );
  OrdBook->notify();
  
  // 输出母单
  std::cout << "Event 1 state: " << observer1.getState() << std::endl;
  std::cout << "Event 2 state: " << observer2.getState() << std::endl;
  
  delete OrdBook;
  return 0;
}
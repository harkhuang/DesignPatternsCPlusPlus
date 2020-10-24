#include <iostream>
#include <string>
#include <vector>

class Job{
public:
    Job(std::string const &name) : name_(name)  {}
    std::string getName() const { return name_; };
private:
std::string name_;
};

class JobSeeker;
class RsumeMarket;
class RsumeMarket {
public:
	void addJob( Job* job) {
        notify(job);
	}

	void notify( Job* job) {
 		for (auto i : v) {
 			i->OnJobPosted(job);
 		}
	}

	void Register(JobSeeker *seeker) {
		v.push_back(seeker);
	}
private:
	std::vector<JobSeeker*> v;
};


class JobSeeker{
    public:
    JobSeeker(std::string const &name) : name_(name){
       
    }

    void OnJobPosted( Job* job){
        std::cout << "New job opportunity" << job->getName() <<std::endl;
    }
private:
    std::string name_;
};


class JobSeeker;







int mian()
{

     RsumeMarket market;
 
       // 求职者
     JobSeeker johnDoe("John Doe");
     JobSeeker jackMa("Jack Ma");
  
     
     // 注册两个人
     market.Register(&johnDoe);
     market.Register(&jackMa);
 
 // 添加一个工作发布工作
 // jobadd 负责通知各个相关的注册
 
 // 对比mvc 这里的添加方法相当于modle方法做类修改或者调整  在对应的  view展现中得到体现  可能是通知  也可能是对应删除 
 
 //  这里通知相应必须展示的方法  
 // 即时通知是必然的   点那个modle有类调整后  但是 我们可以通过控制修改对应的第三方内容
 
     // 在贴士版中添加工作.
 
 
     Job job("Software Engineer");
     market.addJob(&job);

    return 0;
}
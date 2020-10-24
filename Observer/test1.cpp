#include <iostream>
#include <string>
#include <vector>
class JobSeeker;
class Job {
public: 
	Job(std::string const& name) : name_(name) {}
	std::string getName() const { return name_; };
private:
	std::string name_;
};


class JobSeeker {
public:
	JobSeeker(std::string const& name) : name_(name) {

	}

	void OnJobPosted(Job* job) {
		std::cout << "Hi" << name_ << "~~~   New job opportunity :" << job->getName() << std::endl;
	}
private:
	std::string name_;
};


class RsumeMarket {

public:
	void addJob(Job* job) {
		notify(job);
	}

	void notify(Job* job) {
		for (auto i : v) {
			i->OnJobPosted(job);
		}
	}

	void Register(JobSeeker* seeker) {
		v.push_back(seeker);
	}
private:
	std::vector<JobSeeker*> v;
};





int main()
{
	RsumeMarket market;
	// ��ְ��
	JobSeeker johnDoe("John Doe");
	JobSeeker jackMa("Jack Ma");
	// ע��������
	market.Register(&johnDoe);
	market.Register(&jackMa);
	// ���һ��������������
	// jobadd ����֪ͨ������ص�ע��

	// �Ա�mvc �������ӷ����൱��modle���������޸Ļ��ߵ���  �ڶ�Ӧ��  viewչ���еõ�����  ������֪ͨ  Ҳ�����Ƕ�Ӧɾ�� 

	//  ����֪ͨ��Ӧ����չʾ�ķ���  
	// ��ʱ֪ͨ�Ǳ�Ȼ��   ���Ǹ�modle���������  ���� ���ǿ���ͨ�������޸Ķ�Ӧ�ĵ���������

		// ����ʿ������ӹ���.


	Job job("Google Software Engineer ..");
	market.addJob(&job);

	return 0;
}

class Prove {
public: int pos, cost, time;
		Prove(int nposition, int ncost, int ntime) {
			pos = nposition;
			cost = ncost;
			time = ntime;
		}
};

class mycomparison
{
public:
	bool operator() (const Prove& a, const Prove& b) const
	{
		return a.time > b.time;
	}
};

priority_queue<Prove, vector<Prove >, mycomparison> mypq;

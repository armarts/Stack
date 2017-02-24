using namespace std;

class Stack {
		public :
			Stack();
			Stack(int size);
			~Stack();
			int getsize() const;
			double top() const;
			bool isOK() const;
			bool isfull() const;
			bool isempty() const;
			bool dump() const;
			bool push(double value);
			bool pop();
		private :
			double *data_;
			size_t size_;
			const int CAPACITY_;
};


Stack::Stack():
	size_(0),
	CAPACITY_(1000000),
	data_(new double [CAPACITY_])
	{}

Stack::Stack(int size):
	size_(0),
	CAPACITY_(size),
	data_(new double [CAPACITY_])
	{}

Stack::~Stack() {
	delete [] data_;
	size_ = 0;
}

int Stack::getsize() const {
	assert((size_ >= 0) && (size_ < CAPACITY_));
	return size_;
}

double Stack::top() const {
	isOK();
	return data_[size_ - 1];
}

bool Stack::isOK() const {
	assert((size_ >= 0) && (size_ < CAPACITY_));
}

bool Stack::isfull() const {
	isOK();
	return (size_ == CAPACITY_ - 1 ? true : false);
}

bool Stack::isempty() const {
	isOK();
	return (size_ == 0 ? true : false);
}

bool Stack::dump() const {
	if (isempty()) {
		cout << "STACK IS EMPTY " << "\n";
		return false;
	}
	cout << "------------------------- \n";
	for (int iter = size_ - 1; iter >= 0; iter--)
		cout << data_[iter] << "\n";
	cout << "------------------------- \n";
	return true;
}

bool Stack::push(double value) {
	if (!isfull()) {
		data_[size_++] = value;
		return true;
	}
	cout << "STACK IS OVERFLOW \n";
	return false;
}

bool Stack::pop() {
	if (!isempty()) {
		--size_;
		return true;
	}
	cout << "ERROR_POP: STACK IS EMPTY \n";
	assert(0);
}




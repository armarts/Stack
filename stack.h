/**
	Author : Atayan Garik
	format: Stack <typename> st
	Default Constructor create stack with default size (DEFAULT_SIZE = 1)
*/

template <typename T>
class Stack {
	public:

		Stack();
		explicit Stack(int initSize);
		~Stack();
		
		bool isOK() const;
		bool isEmpty() const;
		bool dump() const;
		
		bool stackResize(int resize);
		bool push(T value);
		T pop();
		T top() const;
		size_t getSize() const;		

		static const int DEFAULT_STACK_SIZE = 1;

	private:

		T *m_data;
		size_t m_size;
		size_t m_currentPosition;
};

template <typename T>
Stack<T>::Stack() : m_size(DEFAULT_STACK_SIZE), 
				 m_currentPosition(0),
				 m_data(new T [m_size])
{ }

template <typename T>
Stack<T>::Stack(int initSize) : m_currentPosition(0) {
	assert(initSize >= 0);
	try {
		m_size = initSize;
		m_data = new T [initSize];
	} catch (std::bad_alloc &ex) {
		std::cout << "Internal error\n";
	}
}

template <typename T>
Stack<T>::~Stack() {
	isOK();
	delete [] m_data;
	m_data = NULL;
	m_size = -1;
}

template <typename T>
bool Stack<T>::isOK() const {
	assert(m_data);
	assert(m_size >= 0);
	assert(m_currentPosition >= 0);
	assert((m_currentPosition <= m_size));
	return true;
}

template <typename T>
bool Stack<T>::isEmpty() const {
	isOK();
	return  ((m_currentPosition) ? false : true);
}

template <typename T>
bool Stack<T>::dump() const {
	std::cout << "--------------------\n";
	std::cout << "STACK DUMP : \n";
	std::cout << "STACK SIZE : " << m_size << "\n";
	std::cout << "STACK CURRENT POSITION = " << m_currentPosition << "\n";
	isOK();
	for (size_t i = 0; i < m_currentPosition; i++)
		std::cout << "[" << i << "]" << ":        " << m_data[i] << "\n";
	std::cout << "DUMP HAS DONE\n";
	std::cout << "------------------\n";
}

template <typename T>
bool Stack<T>::stackResize(int resize) {
	try {
		std::cout << "NEW STACK SIZE = " << resize << "\n";
		T *newDataPtr = new T [resize];
		for (int i = 0; i < m_currentPosition; i++)
			newDataPtr[i] = m_data[i];
		delete [] m_data;
		m_size = resize;
		m_data = newDataPtr;
		newDataPtr = NULL;
		return true;
	} catch (std::bad_alloc &ex) {
		return false;
	}		
}

template <typename T>
bool Stack<T>::push(T value) {
	isOK();
	if (m_currentPosition == m_size) {
		std::cout << "STACK IS FULL\n";
		std::cout << "STACK WILL BE RESIZED\n";
		stackResize((m_size * 2) + 1);
	}
	m_data[m_currentPosition++] = value;
	isOK();
}

template <typename T>
T Stack<T>::pop() {
	if (isEmpty()) {
		std::cout << "ERROR POP: STACK IS EMPTY\n";
		assert(0);
	}
	return m_data[--m_currentPosition];
}

template <typename T>
T Stack<T>::top() const {
	if (isEmpty()) {
		std::cout << "ERROR TOP: STACK IS EMPTY\n";
		assert(0);
	}
	return m_data[m_currentPosition - 1];
}

template <typename T>
size_t Stack<T>::getSize() const { 
	isOK();
	return m_size;
}

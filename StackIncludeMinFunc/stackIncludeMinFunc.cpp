/*
 * 题目：包含min函数的栈
 * 问题描述：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
 * 在该栈中，调用min,push或pop的时间复杂度都是O(1)。
 * */

template<typename T>
class StackWithMin
{
  public:
    void push(const T& a);
    T min() const;
    void pop();

  private:
    stack<T> m_min;
    stack<T> m_data;
};



template<typename T> void StackWithMin<T>::push(const T& value)
{
  m_data.push(value);

  if(m_min.size()==0 || value<m_min.top())
    m_min.push(value);
  else
    m_min.push(m_min.top());
}

template<typename T> void StackWithMin<T>::pop()
{
  assert(m_data.size()>0 && m_min.size()>0);

  m_data.pop();
  m_min.pop();
}

template<typename T> T StackWithMin<T>::min() const
{
  assert(m_data.size()>0 && m_min.size()>0);

  return m_min.top();

}


#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	using DataType = int;
	
	while (true)
	{
		system("cls");
		PrintMainTextMenu();

		cout << "Введите номер команды: ";
		Command command = GetValue(Command::STACK, Command::EXIT,
			IsRange);

		switch (command)
		{
			case Command::STACK:
			{
				string menuName("Стек");

				using Stack = Stack<DataType>;
				Stack stack;
				Print<Stack, DataType>(stack, &Stack::Push, &Stack::Pop,
					&Stack::Print, menuName);
				break;
			}
			case Command::DOUBLE_STACK_QUEUE:
			{
				string menuName("Очередь на основе двух стеков");

				using Queue = DoubleStackQueue<DataType>;
				Queue queue;
				Print<Queue, DataType>(queue, &Queue::Enqueue, &Queue::Dequeue,
					&Queue::Print, menuName);
				break;
			}
			case Command::RING_BUFFER:
			{
				string menuName("Кольцевой буфер");

				using Ring = RingBuffer<DataType>;
				cout << "Введите размер буфера: ";
				size_t startingBufferSize = GetValue<size_t>();
				Ring ring(startingBufferSize);

				Print<Ring, DataType>(ring, &Ring::Enqueue, &Ring::Dequeue,
					&Ring::Print, menuName);
				break;
			}
			case Command::EXIT:
			{
				return 0;
			}
		}
	}
}
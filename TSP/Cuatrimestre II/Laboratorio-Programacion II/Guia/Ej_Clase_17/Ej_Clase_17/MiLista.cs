using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ej_Clase_17
{
    class MiLista<T> : IEnumerable, IEnumerator
    {
        T[] list;

        public MiLista()
        {
            list = new T[1];
        }

        public int Count
        {
            get
            {
                return this.list.Length;
            }
        }

        public void Add(T item)
        {
            Array.Resize(ref this.list, this.Count + 1);
            this.list[this.Count - 1] = item;
        }

        public void Remove(T item)
        {
            for (int i = 0; i < this.Count; i++)
            {
                if (!object.ReferenceEquals(this.list[i],null) && this.list[i].Equals(item))
                {
                    for (int j = i; j < this.Count - 1; j++)
                    {
                        this.list[j] = this.list[j + 1];
                    }
                    Array.Resize(ref this.list, this.Count - 1);
                    break;
                }
            }
        }

        public IEnumerator GetEnumerator()
        {
            return this;
        }

        int position = -1;

        object IEnumerator.Current
        {
            get { return Current; }
        }

        public bool MoveNext()
        {
            position++;
            return (position < this.Count);
        }

        public void Reset()
        {
            position = -1;
        }

        public T Current
        {
            get
            {
                try
                {
                    return list[position];
                }
                catch (IndexOutOfRangeException)
                {
                    throw new InvalidOperationException();
                }
            }
        }
    }
}

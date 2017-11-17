#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL)
    {
        returnAux = 0;
        if(this->size < this->reservedSize)
        {
            //this->pElements[this->size] = pElement;
            *((this->pElements)+this->size) = pElement;
            this->size++;
        }
        else if(this->size == this->reservedSize)
        {
            if( resizeUp(this) == 0)
            {
                *((this->pElements)+this->size) = pElement;
                this->size++;
            }
            else
            {
                printf("No se pudo agregar \n");
            }
        }
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index <= this->size)
    {
        returnAux = *((this->pElements)+index);
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL && pElement != NULL)
    {
        returnAux = 0;
        for(i = 0; i < this->size; i++)
        {
            if( *((this->pElements)+i) == pElement)
            {
                returnAux = 1;
            }
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL && index >= 0 && index <= this->size)
    {
        *((this->pElements)+index) = pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this, int index)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= this->size)
    {
        returnAux = contract(this, index);
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        free(this->pElements);
        this->size = 0;
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    int i;

    if(this != NULL)
    {
        if( (returnAux = al_newArrayList()) != NULL )
        {
            for(i = 0; i < this->size; i++)
            {
                *((returnAux->pElements)+i) = *((this->pElements)+i);
            }

        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL && index >= 0 && index <= this->size)
    {
        if(expand(this, index) != -1)
        {
            returnAux = 0;
            this->pElements[index] = pElement;
        }
    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL && pElement != NULL)
    {
        for(i = 0; i < this->size; i++)
        {
            if( *((this->pElements)+i) == pElement )
            {
                returnAux = i;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;
    int i;
    void* pAux;
    int acum = 0;

    if(this != NULL)
    {
        for(i = 0; i < this->size; i++)
        {
            pAux = al_get(this, i);
            if(pAux != NULL)
                acum++;
        }
        if(acum > 0)
            returnAux = 0;
        else
            returnAux = 1;
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < this->size)
    {
        returnAux = al_get(this, index);
        al_remove(this, index);
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this, int from, int to)
{
    void* returnAux = NULL;
    void* pAux = NULL;
    int i;

    if(this != NULL && from >= 0 && to >= 0 && from <= this->size && to <= this->size && from < to)
    {
        if( (pAux = al_newArrayList()) != NULL )
        {
            for(i = 0; i < to-from; i++)
            {
                al_add(pAux, al_get(this,from+i));
            }
            returnAux = pAux;
        }
        else
        {
            printf("No se pudo crear el nuevo array list \n");
            exit(1);
        }
    }

    return returnAux;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this, ArrayList* this2)
{
    int returnAux = -1;
    int i;
    int acum = 0;

    if(this != NULL && this2 != NULL)
    {
        for(i = 0; i < this->size; i++)
        {
            if(al_contains(this, *((this2->pElements)+i)) == 1 )
            {
                acum++;
            }
        }
        if(acum/i == 1)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i;
    void* pAux;
    int flagSwap;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        returnAux = 0;
        do
        {
            flagSwap = 0;
            for(i = 0; i < this->size-1; i++)
            {
                if(order == 1 && pFunc(al_get(this,i), al_get(this,i+1) ) == 1)
                {
                    pAux = *((this->pElements)+i) ;
                    *((this->pElements)+i) = *((this->pElements)+i+1);
                    *((this->pElements)+i+1) = pAux;
                    flagSwap = 1;
                }
                else if(order == 0 && pFunc(al_get(this,i), al_get(this,i+1)) == -1 )
                {
                    pAux = *((this->pElements)+i);
                    *((this->pElements)+i) = *((this->pElements)+i+1);
                    *((this->pElements)+i+1) = pAux;
                    flagSwap = 1;
                }
            }
        }while(flagSwap == 1);
    }

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** pAux;
    int increment = (this->reservedSize)+AL_INCREMENT;

    if(this != NULL)
    {
        if(this->size == this->reservedSize)
        {
            pAux = realloc(this->pElements, (sizeof(void*))*increment);
            if(pAux != NULL)
            {
                this->pElements = pAux;
                this->reservedSize = increment;
                returnAux = 0;
            }
        }
        else
        {
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this, int index)
{
    int returnAux = -1;
    int iSize;

    if(this != NULL && index >= 0 && index <= this->size && resizeUp(this) == 0)
    {
        for(iSize = (this->size)-1; iSize > index; iSize--)
        {
            //*((this->pElements)+iSize) = *((this->pElements)+iSize-1);
            this->pElements[iSize] = this->pElements[iSize-1];
        }
        returnAux = 0;
        this->size++;
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this, int index)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= this->size)
    {
        for( ;index < this->size; index++)
        {
            *((this->pElements)+index) = *((this->pElements)+index+1);
        }
        returnAux = 0;
        this->size--;
    }

    return returnAux;
}

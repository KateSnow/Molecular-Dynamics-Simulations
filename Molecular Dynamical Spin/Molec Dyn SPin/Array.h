// $Id: Array.h,v 1.1.1.1 2007/06/19 02:02:45 awseed Exp $ 

#ifndef HYLIB_ARRAY_HH
#define HYLIB_ARRAY_HH



// 2D Arrays

//-----------------------------------------------------------------------------

/// This creates a 2D array of any type
template <class T>
T** 
New2DArray (T initialValue, int NumRows, int NumCols)
{
    T **Array;
    Array = new T * [NumRows];
    int Row, Col;

    for (Row = 0; Row < NumRows; Row++)
    {
        Array[Row] = new T [NumCols];
    }

    for (Row = 0; Row < NumRows; Row++)
    {
        for (Col = 0; Col < NumCols; Col++)
        {
            Array [Row] [Col] = initialValue;
        }
    }

    return Array;
}



//-----------------------------------------------------------------------------

/// This copies one 2D array to another.

template <class T1, class T2>
void Copy2DArray (T1 **OldArray, T2 **NewArray, int NumRows, int NumCols)
{
    for (int Row = 0; Row < NumRows; Row++)
    {
        for (int Col = 0; Col < NumCols; Col++)
        {
            NewArray [Row] [Col] = (T2) OldArray [Row][Col];
        }
    }
}



//-----------------------------------------------------------------------------

/// This copies one 1D array to another

template <class T1, class T2>
void Copy1DArray (T1 *OldArray, T2 *NewArray, int NumPoints )
{
    for (int Row = 0; Row < NumPoints; Row++)
    {
        NewArray [Row] = (T2) OldArray [Row];
    }
}




//-----------------------------------------------------------------------------

/// Deletes a 2D array

template <class T>
void Clear2DArray (T **Array, int NumRows)
{
    for (int Row = 0; Row < NumRows; Row++)
    {
        delete [] Array [Row];
    }
    delete [] Array;
}


//-----------------------------------------------------------------------------

/// Deletes a 2D array

template <class T>
void Delete2DArray (T **Array, int NumRows)
{
    for (int Row = 0; Row < NumRows; Row++)
    {
        delete [] Array [Row];
    }
    delete [] Array;
}




//=============================================================================
// 3D arrays

/// This creates a 3D array of any type.

template <class T>
T*** New3DArray (T initialValue, int NumRows, int NumCols, int NumLevels)
{
    T ***Array;
    Array = new T **[NumRows];
    int Row, Col, Lev;

    for (Row = 0; Row < NumRows; Row++)
    {
        Array[Row] = new T * [NumCols];
    }

    for (Row = 0; Row < NumRows; Row++)
    {
        for (Col = 0; Col < NumCols; Col++)
        {
            Array [Row][Col] = new T [NumLevels];
        }
    }

    for (Row = 0; Row < NumRows; Row++)
    {
        for (Col = 0; Col < NumCols; Col++)
        {
            for (Lev = 0; Lev < NumLevels; Lev++)
            {
                Array [Row][Col][Lev] = initialValue;
            }
        }
    }

    return Array;
}



//-----------------------------------------------------------------------------


/// This copies one 2D array to another.

template <class T1, class T2>
void Copy3DArray (T1 ***OldArray, T2 ***NewArray,
                  int NumRows, int NumCols, int NumLevels)
{
    int Row, Col, Lev;
    for (Row = 0; Row < NumRows; Row++)
    {
        for (Col = 0; Col < NumCols; Col++)
        {
            for (Lev = 0; Lev < NumLevels; Lev++)
            {
                NewArray [Row][Col][Lev] = (T2) OldArray [Row][Col][Lev];
            }
        }
    }
}



//-----------------------------------------------------------------------------

/// This deletes a 2D array.

template <class T>
void Delete3DArray (T **Array, int NumRows, int NumCols)
{
    int Row, Col;

    for (Row = 0; Row < NumRows; Row++)
    {
        for (Col = 0; Col < NumCols; Col ++)
        {
            delete [] Array [Row][Col];
        }
    }

    for (Row = 0; Row < NumRows; Row++)
    {
        delete [] Array [Row];
    }

    delete [] Array;
}

#endif // HYLIB_ARRAY_HH


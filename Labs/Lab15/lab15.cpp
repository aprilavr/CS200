#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Room
{
    private: string m_title; //room name
    private: int m_width; //room width
    private: int m_length; //room length

    public: int GetWidth()
    {
        return m_width;
    }
    public: int GetLength()
    {
        return m_length;
    }
    public: int GetArea()
    {
        int area= m_width*m_length;
        return area;
    }
    public: string GetTitle()
    {
        return m_title;
    }
    public: void SetTitle( string newTitle )
    {
        m_title=newTitle;
    }
    public: void SetDimensions( int newWidth, int newLength )
    {
        if(newWidth!=0 && newWidth>0)
        {
            m_width=newWidth;
        }

        if(newLength!=0 &&newLength>0)
        {
            m_length=newLength;
        }
    }
};

class Building
{
    private: Room* m_rooms;
    private: int m_roomCount;

    public: Building (int roomCount) //constructor
    {
        m_rooms=nullptr;
        if(roomCount>0)
        {
            m_roomCount=roomCount;
            m_rooms= new Room[roomCount];
        }
    }
    public: ~Building()//destructor
    {
        if(m_rooms!=nullptr)
        {
            delete [] m_rooms;
        }
    }
    public: void SetRoomTitle( int room, string title )
    {
        if(room>=0&&room<m_roomCount)
        {
            m_rooms[room].SetTitle(title);
        }
    }
    public: void SetRoomDimensions( int room, int width, int length )
    {
        if(room>=0&&room<m_roomCount)
        {
            m_rooms[room].SetDimensions(width, length);
        }
    }
    public: int GetTotalArea()
    {
        int areaSum=0;
        for(int i=0; i<m_roomCount; i++)
        {
            areaSum+= m_rooms[i].GetArea();

        }
        return areaSum;
    }
    public: void PrintBuildingInformation( string filename )
{
	ofstream output( filename );

	output << "BUILDING Dimensions: " << GetTotalArea() << " sqft" << endl << endl;

	for ( int i = 0; i < m_roomCount; i++ )
	{
		output << endl << "ROOM " << (i+1) << " ("
			<< m_rooms[i].GetTitle() << "):"
			<< "\n\t * Dimensions: " << m_rooms[i].GetWidth() << " x " << m_rooms[i].GetLength()
			<< "\n\t * Area:       " << m_rooms[i].GetArea() << " sqft" << endl;
	}

	output.close();
}

};

void RoomProgram()
{

    // This function works with the Room object

    Room room;
    room.SetDimensions( 5, 4 );

    cout << "Room area is: " << room.GetArea() << endl;

    room.SetTitle( "closet" );

    cout << "Room name is: " << room.GetTitle() << endl;

}

void BuildingProgram()
{
    // This function works with the Building object

    Building building( 5 );

    building.SetRoomTitle( 0, "Entryway" );
    building.SetRoomTitle( 1, "Living Room" );
    building.SetRoomTitle( 2, "Kitchen" );
    building.SetRoomTitle( 3, "Bedroom" );
    building.SetRoomTitle( 4, "Bathroom" );

    building.SetRoomDimensions( 0, 5, 10 );
    building.SetRoomDimensions( 1, 5, 10 );
    building.SetRoomDimensions( 2, 5, 10 );
    building.SetRoomDimensions( 3, 5, 10 );
    building.SetRoomDimensions( 4, 5, 10 );

    building.PrintBuildingInformation( "building.txt" );
}

int main()
{
    RoomProgram();
    BuildingProgram();

    return 0;
}

#include "Agency.h"
#include <fstream>



Agency::Agency(string file_name){

	ifstream info(file_name);
	vector<string> agency_info;
	string name;
	if (info.is_open())
	{
		while (getline(info, name))
		{
			agency_info.push_back(name);
		}
		info.close();
	}
	else cout << "Unable to open file";

	name = agency_info[0];
	VATnumber = stoi(agency_info[1]);
	URL = agency_info[2];
	//FAZER ISTO DEPOIS address = getAddress(agency_info[3]);

	//
	// Client Information
	ifstream client_info(agency_info[4]);
	string name;
	vector<string> client_list;
	vector<Client> vector_client;
	Client temp_client;

	while (getline(client_info, name))
	{
		if (name != "::::::::::") client_list.push_back(name);
		else
		{
			temp_client.name = client_list[0];
			temp_client.nif = client_list[1];
			temp_client.household = client_list[2];
			temp_client.address = getAddress(client_list[3]);
			temp_client.packs_bought = getPacks(client_list[4]);
			temp_client.total_purchases = temp_client.packs_bought.size();
			vector_client.push_back(temp_client);
			client_list.clear();
		}
	}

	//Add the last client
	temp_client.name = client_list[0];
	temp_client.nif = client_list[1];
	temp_client.household = client_list[2];
	temp_client.address = getAddress(client_list[3]);
	temp_client.packs_bought = getPacks(client_list[4]);
	temp_client.total_purchases = temp_client.packs_bought.size();
	vector_client.push_back(temp_client);
	client_list.clear();
	NiceHolidays.clients = vector_client;
	client_info.close();

	//
	// TravelPack Information
	ifstream pack_info(agency_info[5]);
	vector<string> pack_list;
	vector<TravelPack> vector_pacote;
	TravelPack pacote;

	getline(pack_info, NiceHolidays.lastTravelPack);

	while (getline(pack_info, name))
	{
		if (name != "::::::::::") pack_list.push_back(name);
		else
		{
			pacote.identifier = pack_list[0];
			pacote.locals = pack_list[1];
			pacote.start_date = getDate(pack_list[2]);
			pacote.end_date = getDate(pack_list[3]);
			pacote.price = stoi(pack_list[4]);
			pacote.capacity = pack_list[5];
			pacote.sold = stoi(pack_list[6]);
			vector_pacote.push_back(pacote);
			pack_list.clear();
		}
	}

	//Add the last pack
	pacote.identifier = pack_list[0];
	pacote.locals = pack_list[1];
	pacote.start_date = getDate(pack_list[2]);
	pacote.end_date = getDate(pack_list[3]);
	pacote.price = stoi(pack_list[4]);
	pacote.capacity = pack_list[5];
	pacote.sold = stoi(pack_list[6]);
	vector_pacote.push_back(pacote);
	pack_list.clear();


	pack_info.close();
	NiceHolidays.packages = vector_pacote;

}

  // metodos GET
string Agency::getName() const{

  //  IMPLEMENTATION REQUIRED 
}

unsigned Agency::getVATnumber() const{

  //  IMPLEMENTATION REQUIRED 
}

Address Agency::getAddress() const{

  //  IMPLEMENTATION REQUIRED 
}

string Agency::getURL() const{

  //  IMPLEMENTATION REQUIRED 
}

vector<Client> Agency::getClients() const{

  //  IMPLEMENTATION REQUIRED 
}

vector<Packet> Agency::getPackets() const{

  //  IMPLEMENTATION REQUIRED 
}

  
  // SET Methods

void Agency::setName(string name){

  //  IMPLEMENTATION REQUIRED 
}

void Agency::setVATnumber(unsigned VATnumber){

  //  IMPLEMENTATION REQUIRED 
}

void Agency::setAddress(Address address){

  //  IMPLEMENTATION REQUIRED 
}
  void Agency::setURL(string url){

  //  IMPLEMENTATION REQUIRED 

}
  void Agency::setClients(vector<Client> & clients){

  //  IMPLEMENTATION REQUIRED 

  }
  void Agency::setPackets(vector<Packet> & packets){

  //  IMPLEMENTATION REQUIRED 

}

/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency & agency){

  // A IMPLEMENTATION REQUIRED 
}

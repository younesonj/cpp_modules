#include <iostream>
#include <list>
class YoutubeChannel {
    private :
        std::string Name;
        std::string OwnerName;
        int SubsCount;
        std::list<std::string> videos;

    public :

    YoutubeChannel(std::string name, std::string owner)
    {
        Name = name;
        OwnerName = owner;
        SubsCount = 0;
    }

    void    GetInfos()
    {
        std::cout << "Name is : " << Name << std::endl;
        std::cout << "Owner Name is : " << OwnerName << std::endl;
        std::cout << "Subs count : " << SubsCount << std::endl;
        std::cout << "Vidoes :" << std::endl;
        for (std::string iter : videos)
            std::cout << iter << std::endl;
    }

    void    increment_subs()
    {
        SubsCount += 127;
    }

    void    add_list(std::string lst)
    {
        videos.push_back(lst);
    }

};

class GamingYoutubeChannel : public YoutubeChannel{
    public :
        GamingYoutubeChannel(std::string name, std::string owner):YoutubeChannel(name, owner)
        {

        }
};


int main ()
{
    GamingYoutubeChannel YTchannel("Younes Games", "Younes");
    YTchannel.GetInfos();




    return (0);
}
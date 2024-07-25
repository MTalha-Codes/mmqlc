#include "ReadView__WriteSave.hpp"




int main(int argc , char *argv[])
{
    std::unique_ptr<ReadView_WriteSave> rv_ws;
    try
    {
        rv_ws = std::make_unique<ReadView_WriteSave>(argc , argv);
        try
        {
            rv_ws->MMQL_RV_WS();
        }
        catch(const std::runtime_error &re)
        {
            std::cout << "Exception Thrown: " << hue::red << re.what() << hue::reset <<std::endl;
            return -1;
        }
    }
    catch(const std::runtime_error &re)
    {
        std::cout << "Exception Thrown: " << hue::red << re.what() << hue::reset <<std::endl;
        return -1;
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <fstream>
using namespace std;

const int ReadCsvData(const char* lpszFilename, vector<vector<string> > &vlStr)
{
/// 2、打开CSV文件
    ifstream _streamFromFile(lpszFilename);
///    判断打开文件是否成功
    if (NULL == _streamFromFile)
        return (-errno);
/// 存储读取的文件内容
    string _strIn("");
/// 3、读取一行
    int cnt=0;
    while (getline(_streamFromFile, _strIn))
    {
        //  cout<<cnt++<<endl;
        vector<string> _ltStr;
        while (_strIn.size()>0)
        {
            //          cout<<_strIn<<endl;
            //             cout<<_strIn.find_first_of(',');
            //          cout<<_strIn<<endl;
            size_t nc=_strIn.find_first_of(',');
            if(nc>_strIn.size())
                nc=_strIn.size()-1;
            _ltStr.push_back(_strIn.substr(0,nc));
            _strIn=_strIn.substr(nc+1,_strIn.size());
        }
        vlStr.push_back(_ltStr);
        _strIn.assign("");
    }


    return 0;
}

void createInsertSQL_taobao_diandian_takeout_settlement(vector<vector<string> > &data)
{
    for(size_t i=0; i<data.size(); i++)
    {
        cout<<"insert into taobao_diandian_report.takeout_settlement values("
            <<i+1<<','
            <<"'"<<data[i][2]<<"'"<<','     //gmt_create
            <<"'"<<data[i][3]<<"'"<<','          //gmt_modified
            <<1         <<','               //city_id
            <<"'"<<data[i][1]<<"'"<<','     //city_name
            <<"'"<<data[i][2]<<"'"<<','     //open_audit_date
            <<0<<','              //shop_id
            <<"'"<<data[i][4]<<"'"<<','     //shop_name
            <<"'"<<data[i][5]<<"'"<<','          //shop_sub_name
            <<data[i][6]<<','               //seller_id
            <<"'"<<data[i][7]<<"'"<<','     //seller_nick
            <<1<<','                        //run_shop_num
            <<data[i][15]<<','              //oder_num
            <<data[i][15]<<','              //success_oder_num
            <<data[i][16]<<','              //success_order_amount
            <<data[i][13]<<','              // auction_num
            <<data[i][14]<<','              // online_auction_num
            <<data[i][17]<<','              //offline_day_num
            <<"'自助餐'"<<','            //shop_type
            <<"123456"<<','                 //open_server_uid
            <<"'"<<data[i][30]<<"'"<<','         //open_server_name
            <<"654321"<<','                 //open_server_emp_uid
            <<"'"<<data[i][11]<<"'"<<','         //open_server_emp_name
            <<"'"<<data[i][0]<<"'"           //localstore_id
            <<");"<<endl;
        cout.flush();
    }
}


void createInsertSQL_taobao_diandian_eatin_settlement(vector<vector<string> > &data)
{
    for(size_t i=0; i<data.size(); i++)
    {
        cout<<"insert into taobao_diandian_report.eatin_settlement values("
            <<i+1<<','
            <<"'"<<data[i][2]<<"'"<<','     //gmt_create
            <<"'"<<data[i][3]<<"'"<<','          //gmt_modified
            <<1         <<','               //city_id
            <<"'"<<data[i][1]<<"'"<<','     //city_name
            <<"'"<<data[i][2]<<"'"<<','     //open_audit_date
            <<"'"<<data[i][0]<<"'"<<','           //localstore_id
            <<"'"<<data[i][4]<<"'"<<','     //shop_name
            <<"'"<<data[i][5]<<"'"<<','          //shop_sub_name
            <<"'openBiz'"<<','                //openBiz
            <<data[i][6]<<','               //seller_id
            <<"'"<<data[i][7]<<"'"<<','     //seller_nick
            <<1<<','                        //run_shop_num
            <<data[i][15]<<','              //oder_num
            <<data[i][15]<<','              //success_oder_num
            <<data[i][16]<<','              //success_order_amount
            <<data[i][13]<<','              // auction_num
            <<data[i][14]<<','              // online_auction_num
            <<data[i][17]<<','              //offline_day_num
            <<"'yes'"<<','                  //has_valid_evoucher
            <<"0"<<','                       //online_evoucher_inventory
            <<"0"<<','                        //evoucher_shortest_period
            <<"'自助餐'"<<','            //shop_type
            <<"123456"<<','                 //open_server_uid
            <<"'"<<data[i][30]<<"'"<<','         //open_server_name
            <<"654321"<<','                 //open_server_emp_uid
            <<"'"<<data[i][11]<<"'"        //open_server_emp_name

            <<");"<<endl;
        cout.flush();
    }
}

void createInsertSQL_taobao_diandian_takeout_settlement_ext(vector<vector<string> > &data)
{
    for(size_t i=0; i<data.size(); i++)
    {
        cout<<"insert into taobao_diandian_report.takeout_settlement_ext values("
            <<"NULL"<<','                           //id
            <<"'2014-8-11'"<<','                 //gmt_create
            <<"'2014-8-11'"<<','                 //gmt_modified
            <<"0"<<','                          //shop_id
            <<1<<','                             //open_store_status
            <<"'可结算'"<<','                   //open_check_result
            <<"123456"<<','                     //open_check_uid
            <<"'"<<"验收人"<<"'"<<','                      //open_check_name
            <<"'"<<"Nick"<<"'"<<','                       //open_check_nick
            <<"'备注'"<<','                         //open_check_remark
            <<"'已通知开票'"<<','                        //open_ticket_status
            <<"'"<<data[i][1] <<"'"<<','              //open_fpm_no
            <<"1"<<','                               //open_progress
            <<"'"<<data[i][3] <<"'"<<','              //open_version
            <<"'123321'"<<','                       // open_server_uid
            <<"'"<<data[i][4]<<"'"<<','                       // open_server_name
            <<"101"<<','                             //trace_shop_status
            <<"NULL"<<','            //trace_check_result
            <<"654321"<<','                 //trace_check_uid
            <<"NULL"<<','         //trace_check_nick
            <<"NULL"<<','                  //trace_check_name
            <<"NULL"<<','          //trace_check_remark
            <<"NULL"<<','            //trace_ticket_status
            <<"NULL"<<','           //trace_fpm_no
            <<"NULL"<<','           //trace_progress
            <<"NULL"<<','           //trace_version
            <<"789456"<<','           //trace_server_uid
            <<"NULL"<<','           //trace_server_name
            <<"NULL"<<','           //extend
            <<"creator"<<','           //creator
            <<"modifier"<<','           //modifier
            <<"'"<<data[i][0]<<"'"        //localstore_id
            <<");"<<endl;
        cout.flush();
    }
}

void createInsertSQL_taobao_diandian_eatin_settlement_ext(vector<vector<string> > &data)
{
    for(size_t i=0; i<data.size(); i++)
    {
        cout<<"insert into taobao_diandian_report.eatin_settlement_ext values("
            <<"NULL"<<','                           //id
            <<"'2014-8-11'"<<','                 //gmt_create
            <<"'2014-8-11'"<<','                 //gmt_modified
            <<"'"<<data[i][0]<<"',"        //localstore_id
            <<1<<','                             //open_store_status
            <<"'可结算'"<<','                   //open_check_result
            <<"123456"<<','                     //open_check_uid
            <<"'"<<"验收人"<<"'"<<','                      //open_check_name
            <<"'"<<"Nick"<<"'"<<','                       //open_check_nick
            <<"'备注'"<<','                         //open_check_remark
            <<"'已通知开票'"<<','                        //open_ticket_status
            <<"'"<<data[i][1] <<"'"<<','              //open_fpm_no
            <<"1"<<','                               //open_progress
            <<"'"<<data[i][3] <<"'"<<','              //open_version
            <<"'123321'"<<','                       // open_server_uid
            <<"'"<<data[i][4]<<"'"<<','                       // open_server_name
            <<"101"<<','                             //trace_shop_status
            <<"NULL"<<','            //trace_check_result
            <<"654321"<<','                 //trace_check_uid
            <<"NULL"<<','         //trace_check_nick
            <<"NULL"<<','                  //trace_check_name
            <<"NULL"<<','          //trace_check_remark
            <<"NULL"<<','            //trace_ticket_status
            <<"NULL"<<','           //trace_fpm_no
            <<"NULL"<<','           //trace_progress
            <<"NULL"<<','           //trace_version
            <<"789456"<<','           //trace_server_uid
            <<"NULL"<<','           //trace_server_name
            <<"NULL"<<','           //extend
            <<"creator"<<','           //creator
            <<"modifier"           //modifier
            <<");"<<endl;
        cout.flush();
    }
}

int main()
{
    freopen("out.txt","w",stdout);
    vector<vector<string> > data;
    ReadCsvData("d:/settlementServer.csv",data);
    cout<<data.size()<<endl;
  //  createInsertSQL_taobao_diandian_eatin_settlement(data);
  createInsertSQL_taobao_diandian_eatin_settlement_ext(data);
    return 0;
}

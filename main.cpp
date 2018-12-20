#include <iostream>
#include "searchrequest.pb.h"

int main(void)
{
    //验证头文件版本和库版本是否兼容
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    
    //实例对象
    TestDemo::SearchRequest writer;
    
    //对象成员赋值
    writer.set_query("set query");
    writer.set_page_number(100);
    writer.set_result_per_page(30);
    writer.set_money_1(41.1);
    writer.set_money_2(42.1);

    //数组类型添加成员
    writer.add_samples(1);
    writer.add_samples(2);
    writer.add_samples(3);
    writer.add_samples(4);
    writer.add_samples(3);
    writer.add_samples(2);
    writer.add_samples(1);

    //枚举类型赋值
    writer.set_corpus(TestDemo::SearchRequest_Corpus_NEWS);

    //对象类型操作
    TestDemo::Result *result = writer.mutable_result();
    result->set_url("wwww.baidu.com");
    result->set_title("baidu");
    result->add_snippets("a");
    result->add_snippets("b");
    result->add_snippets("c");

    //序列化为string
    std::string in_data;
    writer.SerializeToString(&in_data);

    //std::cout << "in_data:" << in_data << std::endl;

    //反序列化为bp对象
    TestDemo::SearchRequest reader;
    reader.ParseFromString(in_data);
    
    //打印
    std::cout << "query:" << reader.query() << std::endl;
    std::cout << "page_number:" << reader.page_number() << std::endl;
    std::cout << "result_per_page:" << reader.result_per_page() << std::endl;
    std::cout << "money_1:" << reader.money_1() << std::endl;
    std::cout << "money_2:" << reader.money_2() << std::endl;

    //打印数组类型
    std::cout << "samples:";
    for( int i = 0; i < writer.samples_size(); i++ )
    {
        std::cout << writer.samples(i) << "  ";
    }
    std::cout << std::endl;

    std::cout << "corpus:" << reader.corpus() << std::endl;

    TestDemo::Result *result_r = reader.mutable_result();

    std::cout << "result::url:" << result_r->url() << std::endl;
    std::cout << "result::title:" << result_r->title() << std::endl;

    std::cout << "result::snippets:" ;
    for( int i = 0; i <result_r->snippets_size(); i++ )
    {
        std::cout << result_r->snippets(i) << " ";
    }
    std::cout << std::endl;

    //释放内存
    google::protobuf::ShutdownProtobufLibrary();
}

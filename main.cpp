#include <iostream>
#include "searchrequest.pb.h"
#include "searchrequest_new1.pb.h"
#include "searchrequest_new2.pb.h"
#include "searchrequest_new3.pb.h"
#include "searchrequest_new4.pb.h"

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

    std::cout << "---------------TestDemo协议-------------------" << std::endl;

    std::cout << "同协议反序列化" << std::endl;
    {
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
    }

    std::cout << "---------------TestDemoNew1------------------" << std::endl;

    std::string in_data1;
    std::string in_data2;

    std::cout << "TestDemo协议反序列化为TestDemoNew1协议" << std::endl;
    std::cout << "新协议添加字段new1(string) new2(string) new3(string) new4(string) new5(string)" << std::endl;

    {
        //反序列化为bp对象
        TestDemoNew1::SearchRequest reader;
        reader.ParseFromString(in_data);

        //TestDemoNew1 序列化为in_data1
        reader.set_new1("TestDemoNew1 set new1");
        reader.set_new2("TestDemoNew1 set new2");
        reader.set_new3("TestDemoNew1 set new3");
        reader.set_new4("TestDemoNew1 set new4");
        reader.set_new5("TestDemoNew1 set new5");

        reader.SerializeToString(&in_data1);
        reader.SerializeToString(&in_data2);

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

        TestDemoNew1::Result *result_r = reader.mutable_result();

        std::cout << "result::url:" << result_r->url() << std::endl;
        std::cout << "result::title:" << result_r->title() << std::endl;

        std::cout << "result::snippets:" ;
        for( int i = 0; i <result_r->snippets_size(); i++ )
        {
            std::cout << result_r->snippets(i) << " ";
        }
        std::cout << std::endl;

        std::cout << "new1:" << reader.new1() << std::endl;
        std::cout << "new2:" << reader.new2() << std::endl;
        std::cout << "new3:" << reader.new3() << std::endl;
        std::cout << "new4:" << reader.new4() << std::endl;
        std::cout << "new5:" << reader.new5() << std::endl;
    }

    std::cout << "---------------TestDemoNew2------------------" << std::endl;

    std::cout << "TestDemo1协议反序列化为TestDemoNew2协议" << std::endl;
    std::cout << "新协议添加字段new1(string) new11(string) new2(string) new3(string) new4(string) new5(string)" << std::endl;

    {

        //反序列化in_data1为bp对象
        TestDemoNew2::SearchRequest reader;
        reader.ParseFromString(in_data1);

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

        TestDemoNew2::Result *result_r = reader.mutable_result();

        std::cout << "result::url:" << result_r->url() << std::endl;
        std::cout << "result::title:" << result_r->title() << std::endl;

        std::cout << "result::snippets:" ;
        for( int i = 0; i <result_r->snippets_size(); i++ )
        {
            std::cout << result_r->snippets(i) << " ";
        }
        std::cout << std::endl;

        std::cout << "new1:"  << reader.new1()  << std::endl;
        std::cout << "new11:" << reader.new11() << std::endl;
        std::cout << "new2:"  << reader.new2()  << std::endl;
        std::cout << "new3:"  << reader.new3()  << std::endl;
        std::cout << "new4:"  << reader.new4()  << std::endl;
        std::cout << "new5:"  << reader.new5()  << std::endl;
    }

    std::cout << "---------------TestDemoNew3------------------" << std::endl;

    std::cout << "TestDemo1协议反序列化为TestDemoNew3协议" << std::endl;
    std::cout << "新协议添加字段new1(string) new2(string) new2(uint32) new3(string) new4(string) new5(string)" << std::endl;

    {

        //反序列化in_data1为bp对象
        TestDemoNew3::SearchRequest reader;
        reader.ParseFromString(in_data1);

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

        TestDemoNew3::Result *result_r = reader.mutable_result();

        std::cout << "result::url:" << result_r->url() << std::endl;
        std::cout << "result::title:" << result_r->title() << std::endl;

        std::cout << "result::snippets:" ;
        for( int i = 0; i <result_r->snippets_size(); i++ )
        {
            std::cout << result_r->snippets(i) << " ";
        }
        std::cout << std::endl;

        std::cout << "new1:"  << reader.new1()  << std::endl;
        std::cout << "new2:"  << reader.new2()  << std::endl;
        std::cout << "new22:" << reader.new22() << std::endl;
        std::cout << "new3:"  << reader.new3()  << std::endl;
        std::cout << "new4:"  << reader.new4()  << std::endl;
        std::cout << "new5:"  << reader.new5()  << std::endl;
    }

    std::cout << "---------------TestDemoNew4------------------" << std::endl;

    std::cout << "TestDemo1协议反序列化为TestDemoNew4协议" << std::endl;
    std::cout << "新协议添加字段Result: title1 title2 title3" << std::endl;

    {

        //反序列化in_data1为bp对象
        TestDemoNew4::SearchRequest reader;
        reader.ParseFromString(in_data2);

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

        TestDemoNew4::Result *result_r = reader.mutable_result();

        std::cout << "result::url:" << result_r->url() << std::endl;
        std::cout << "result::title:" << result_r->title() << std::endl;
        std::cout << "result::title1:" << result_r->title1() << std::endl;
        std::cout << "result::title2:" << result_r->title2() << std::endl;
        std::cout << "result::title3:" << result_r->title3() << std::endl;

        std::cout << "result::snippets:" ;
        for( int i = 0; i <result_r->snippets_size(); i++ )
        {
            std::cout << result_r->snippets(i) << " ";
        }
        std::cout << std::endl;

        std::cout << "new1:"  << reader.new1()  << std::endl;
        std::cout << "new2:"  << reader.new2()  << std::endl;
        std::cout << "new3:"  << reader.new3()  << std::endl;
        std::cout << "new4:"  << reader.new4()  << std::endl;
        std::cout << "new5:"  << reader.new5()  << std::endl;
    }
    //释放内存
    google::protobuf::ShutdownProtobufLibrary();
}

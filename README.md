# protobuf_test
protobuf_test 是protobuf2版本的实验程序
**前后兼容注意事项**
1. 不可以改变已经存在的标签的数字。
2. 不可以增加或删除必须(required)字段。
3. 可以删除可选(optional)或重复(repeated)字段。
4. 可以添加新的可选或重复字段，但是必须使用新的标签数字，必须是之前的字段所没有用过的。

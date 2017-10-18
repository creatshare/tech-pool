<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/18
 * Time: 14:47
 */
define("TOKEN","Huabuxiu");
$wechatObj = new wechat_php();
$wechatObj->responseMsg();

class wechat_php
{
    public function responseMsg()
    {
        $postStr = file_get_contents("php://input");
        if (!empty($postStr)) {
            $postObj = simplexml_load_string($postStr, 'SimpleXMLElement', LIBXML_NOCDATA);
            $fromUsername = $postObj->FromUserName;
            $toUsername = $postObj->ToUserName;
            $keyword = $postObj->Content;
            $time = time();
            //回复消息的XML格式
            $textTpl = "<xml>
              <ToUserName><![CDATA[%s]]></ToUserName>
              <FromUserName><![CDATA[%s]]></FromUserName>
              <CreateTime>%s</CreateTime>
              <MsgType><![CDATA[%s]]></MsgType>
              <Content><![CDATA[%s]]></Content>
              <FuncFlag>0</FuncFlag>
            </xml>";
            if(!empty( $keyword ))
            {
                $msgType = "text";
                $contentStr = "";
                $resultStr = sprintf($textTpl, $toUsername, $fromUsername, $time, $msgType, $contentStr);
                echo $resultStr;
            }
//            $textTpl = "<xml>
//                <ToUserName><![CDATA[%s]]> </ToUserName>
//                <FromUserName><![CDATA[%s]]></FromUserName>
//                <CreateTime>%s</CreateTime>
//                <MsgType><![CDATA[%s]]></MsgType>
//                <Content><![CDATA[%s]]></Content>
//                <FuncFlag>0</FuncFlag>
//                </xml>";
//            if (!empty($keyword)){
//                $msgType = "text";
//                $contentStr = "成功!";
//                $resultStr = sprintf($textTpl, $fromUsername, $toUsername, $time, $msgType, $contentStr);
//                echo $resultStr;
//                exit();
//            }
        }
    }
}
//else{
//                echo "请输入关键字";
//            }
//            }else{
//                echo "";
//                exit;
//            }
//    }
//}

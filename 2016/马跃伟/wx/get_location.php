<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/25
 * Time: 14:08
 */
$wechatObject = new wechat_php();
$wechatObject->GetLocationMsg();

class WeChat_php{
    public function GetLocationMsg()
    {
        $postStr = file_get_contents("php://input");

        if (!empty($postStr)){
            $postObj = simplexml_load_string($postStr,'SimpleXMLElement',LIBXML_NOCDATA);
            $fromUsername = $postObj->FromUserName;
            $toUsername = $postObj->ToUserName;
            $msgType = $postObj->MsgType;
            $location_X = trim($postObj->Location_X);
            $location_Y = trim($postObj->Location_Y);
            $scale = trim($postObj->Scale);
            $label = trim($postObj->Lable);
            $msgId = trim($postObj->MsgId);
            $time = time();

            $textTpl = "<xml>
                        <ToUserName><![CDATA[%s]]></ToUserName>
							<FromUserName><![CDATA[%s]]></FromUserName>
							<CreateTime>%s</CreateTime>
							<MsgType><![CDATA[text]]></MsgType>
							<Content><![CDATA[%s]]></Content>
							<FuncFlag>0</FuncFlag>
                             </xml> ";
            $contentStr = "Location_X : ".$location_X."\n";
            $contentStr = $contentStr."Location_Y : ".$location_Y."\n";
            $contentStr = $contentStr."Scale : ".$scale."\n";
            $contentStr = $contentStr."Label : ".$label;
        }
        $resultStr = sprintf($textTpl,$fromUsername,$toUsername,$time,$contentStr);
        echo $resultStr;
    }
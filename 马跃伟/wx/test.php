<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/18
 * Time: 15:52
 */
define("TOKEN","Huabuxiu");
$wechatObj = new wechatObj_php();
$wechatObj->responseMsg();

class wechatObj_php{
    public function responseMsg(){
        $postStr = $GLOBALS["HTTP_RAW_POST_DATA"];
        if(!empty($postStr))
        {
            $postObj = simplexml_load_string($postStr,'SimpleXMLElement',LIBXML_NOCDATA);
            $msgType = $postObj->MsgType;
            $keyword = trim($postObj->Content);
            if($msgType == "")
                echo pass;
        }
    }
}

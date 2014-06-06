/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package struts2.tag;
import org.apache.struts2.util.IteratorGenerator.Converter;
/**
 *
 * @author Administrator
 */
public class MyConverter implements Converter{
 public Object convert(String value) throws Exception {
                String[] temp = value.split(":");
                if (temp.length == 2) {
                    MapClass map = new MapClass(temp[0], temp[1]);

                    return map;
                }
                return null;
            }
 class MapClass {

        private String key;
        private String value;

        public MapClass() {
        }

        public MapClass(String key, String value) {
            this.key = key;
            this.value = value;
        }

        public String getKey() {
            return key;
        }

        public void setKey(String key) {
            this.key = key;
        }

        public String getValue() {
            return value;
        }

        public void setValue(String value) {
            this.value = value;
        }
    }
}


/**********************************************************************************************
    This file is part of PriiDash(TM), an enhanced instrument panel and
    data logger for the Prius and more.
    Copyright (C) 2011 by TeamPrii at sourceforge.net

    PriiDash(TM) is provided "AS IS" under the terms of
    the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version, WITH ADDITIONAL TERMS in
    paragraphs below.

    This program is distributed in the hope that it will be useful,
    but Without Any Warranty; without even the implied warranty of
    Merchantability or Fitness For A Particular Purpose.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    ADDITIONAL TERMS

    IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, DEATH; INJURY; COLLISION AND/OR DAMAGE TO VEHICLES;
    LIABILITY FOR ACCIDENTS AND/OR TRAFFIC VIOLATIONS; PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE OR
    INABILITY TO USE THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    THE AUTHOR RESERVES ALL RIGHTS OF OWNERSHIP OF THE NAME OF THE SOFTWARE, PriiDash(TM).
    ALL MODIFIED VERSIONS MUST BE CLEARLY MARKED AS BEING DIFFERENT FROM THE ORIGINAL,
    AND MUST CARRY ACKNOWLEDGEMENT TO THE ORIGINAL AUTHOR, TeamPrii at sourceforge.net.
    ALL ADVERTISING MATERIALS MENTIONING FEATURES OR USE OF THIS SOFTWARE
    MUST DISPLAY THE FOLLOWING ACKNOWLEDGEMENT:
    This product includes the software PriiDash(TM) developed by
    TeamPrii at sourceforge.net.

    To contact the author: look up TeamPrii at sourceforge.net.
    Project home page: http://priidash.sourceforge.net/
************************************************************************************************/


#ifndef _OBD_H
#define	_OBD_H
int openport(const char *portname);
void sendcmd(const char *cmd, int fd, FILE *fplog);
int readandlogdata(int fd, FILE *fplog);
void sendsettingscmd(const char *cmd, int fd, FILE *fplog); // send OBD command, read reply and log to file but no car data extraction
void initOBD(int fd, FILE *fplog);// initialize OBDUSB device
int readquerydata(int fd, FILE *fplog, car_data *cd, Gauges *gs);// read, extract data and log messages in request/reply mode
int sendquerycmd(const char *cmd, int fd, FILE *fplog, car_data *cd, Gauges *gs);// send, read, extract data and log messages in request/reply mode
void queryOBD(int fd, FILE *fplog, car_data *cd, Gauges *gs);// query for data i.e. request/reply mode
void setupATMA(int fd, FILE *fplog);// set up ATMA
int readATMAdata(char *str, const int maxlen, int *partialmsglen, int fd, FILE *fplog, car_data *cd, Gauges *gs);
    // read ATMA messages into string then log them and extract data from them, leave remaining partial message at beginning of str and return its length in *partialmsglen
    
#endif	/* _OBD_H */

